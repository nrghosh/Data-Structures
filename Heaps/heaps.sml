(*  Leftist heaps.
*
*   Nikhil Ghosh
*   
*)

structure Final =
struct

  (*  Invariant:  for a leftist heap h = N(x, r, h1, h2),
  *   r = rank(h) = 1 + rank(h2); every heap satisfies the
  *   heap property.  This structure implements min-heaps.
  *)
  datatype 'a heap = E | N of 'a * int * 'a heap * 'a heap

  (*  The type of priority queues with keys of type 'a.
  *)
  type 'a pri_q = ('a heap) * ('a*'a -> order)

  (*  Exception that is raised when deleteMin or getMin is called on an
  *   empty priority queue.
  *)
  exception Empty

  exception Unimplemented

  (*  empty cmp = (E, cmp)
  *
  *   Create an empty priority queue, where cmp will be used to compare
  *   priorities of keys added to this priority queue.
  *)
  fun empty (cmp : 'a*'a -> order) =
    (E, cmp)

  (*  isEmpty (t, _) = true if keys(t) is empty, false o/w.
  *)
  fun isEmpty ((h, _) : 'a pri_q) : bool =
    case h of
      E => true
    | _ => false

  (* rank (t) = r where r is the rank of the heap
  *)
  fun rank(h : 'a heap) : int =
    case h of
      E => 0
    | N(_, r, _, _) => r

  (* makeH (x, r, h1, h2) = h', where keys(h') = keys(h1) + keys(h2) + {x}
  *)
  fun makeH (x : 'a, h1 : 'a heap, h2 : 'a heap) : 'a heap =
  let
    val r = 1 + rank(h2)
  in
    N(x, r, h1, h2)
  end

  (*  insert((h, cmp), x) = (h', cmp), where keys(h') = keys(h) + {x}.
  *)
  fun insert ((h, cmp) : 'a pri_q, x : 'a) : 'a pri_q =
  let
    fun insert' (p : 'a heap) : 'a heap =
      case p of
        E => N(x, 1, E, E)
      | N(y, r, h1, h2) =>
          case cmp(x, y) of
            GREATER => makeH(y, h1, insert'(h2))
          | _ => makeH(x, h, E)
  in
    (insert'(h), cmp)
  end

  (*  deleteMin (h, cmp) = (h', cmp), where keys(h') = keys(h) - getMin(h).
  *)
  fun deleteMin ((h, cmp) : 'a pri_q) : 'a pri_q =
  let
  (* merge(h1, h2) = h' where keys(h') = keys(h1) + keys(h2)
  *  pre-condition: h1 and h2 both are leftist trees
  *)
    fun merge(h1 : 'a heap, h2 : 'a heap, cmp : 'a*'a -> order ) : 'a heap =
      case (h1, h2) of
        (E, _) => h2
      | (N(x, _, a1, a2), N(y, _, b1, b2)) =>
        case cmp(x, y) of
          GREATER => makeH(x, merge(a1, a2, cmp), h2)
        | _ => makeH(y, merge(b1, b2, cmp), h1)
  in
    case h of
      E => (E, cmp)
    | N(x, _, h1, h2) => (merge(h1, h2, cmp), cmp)
  end

  (*  getMin (h, cmp) = x, where x = min(keys(h)), where the order is defined
  *   by cmp.
  *)
  fun getMin ((h, cmp) : 'a pri_q) : 'a =
    case h of
      E => raise Empty
    | N(x, _, h1, h2) => x

  (*  toString itemToString (t, cmp) = a string representation of keys(t),
  *   where the string representation of the key x is itemToString x.
  *)
  fun toString (itemToString : 'a -> string) ((t, _) : 'a pri_q) : string =
  let
    (*  pad(s, n1, m1, m2, n2) =
    *     "    ----" ^ s ^ "----    "
    *   (n1 leading spaces, m1 leading dashes, m2 trailing dashes, n2 trailing
    *   spaces).
    *)
    fun pad(s, n1, m1, m2, n2) =
      (implode (List.tabulate(n1, fn _ => #" "))) ^
      (implode (List.tabulate(m1, fn _ => #"-"))) ^
      s ^
      (implode (List.tabulate(m2, fn _ => #"-"))) ^
      (implode (List.tabulate(n2, fn _ => #" ")))

    (*  merge ([s_0,...], n1, [s_0',...], n2, n) =
    *     [..., s_i ^ "   " ^ s_i',...]
    *     (n spaces).  Each element of the result list has length n1+n+n2.
    *)
    fun merge(ss1 : string list, n1 : int, ss2 : string list, n2 : int, n) :
        string list =
      case (ss1, ss2) of
           ([], _) => map (fn s => pad (s, n1+n, 0, 0, 0)) ss2
         | (_, []) => map (fn s => pad (s, 0, 0, 0, n2+n)) ss1
         | (s1 :: ss1, s2 :: ss2) =>
             ((pad(s1, 0, 0, 0, n div 2)) ^ (pad(s2, n-(n div 2), 0, 0, 0))) ::
               merge(ss1, n1, ss2, n2, n)

    (*  treeToString(t) = ([s_0,...,s_{m-1}], n, m1, m2), where:
    *     * s_0 ^ "\n" ^ s_1 ^ "\n" ^ ... ^ "\n" ^ s_{m-1} is a string
    *       representation of t.
    *     * String.size(s_i) = n for all i.
    *     * String.sub(s_0, m1) is the first character of the root rep'n
    *       in s_0.
    *     * String.sub(s_0, n1) is the last character of the root rep'n
    *       in s_0.
    *)
    fun treeToString (t : 'a heap) : (string list)*int*int*int =
      case t of
           E => (["[]"], 2, 0, 1)
         | N(x, r, t1, t2) =>
             let
               val (ss1, n1, m11, m12) = treeToString t1
               val (ss2, n2, m21, m22) = treeToString t2
               val s = String.concat [itemToString x, "(", Int.toString r, ")"]
               val n = String.size s
             in
               (pad(s, m11, n1-m11, m22+1, n2-m22-1) ::
                 merge(ss1, n1, ss2, n2, n),
                 n1+n2+n, n1, n1+n-1)
             end
   in
    String.concatWith "\n" (#1(treeToString t))
   end
  end

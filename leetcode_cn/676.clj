(defn comp_str_inner
  [s1 s2 once]
  (cond
    (not= (count s1) (count s2)) false
    (empty? s1) once
    (empty? s2) once
    (= (first s1) (first s2)) (comp_str_inner (rest s1) (rest s2) once)
    once false
    :else (comp_str_inner (rest s1) (rest s2) true)))

(defn comp_str
  [s1 s2]
  (comp_str_inner s1 s2 false))

(defn comp_strs
  [s, iter]
  (some #(comp_str s %) iter))

(defn input
  []
  ["hello" "leetcode"])

(comp_strs "hello" (input))
(comp_strs "hhllo" (input))


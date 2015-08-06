I = [(l0, r0), (l1, r1), ... (l(m-1), r(m-1))]
J = [(l0, r0), (l1, r1), ... (l(n-1), r(n-1))]

li < ri < l(i+1)

I = [(1, 20), (21, 25), ...1000..., (4567, 5222)]
J = [(-10, -6), (-5, 2), (10, 11), (20, 25), (30, 50), (60, 100), ...]

(1, 20), (10, 11)
(1, 20), (20, 25)
(21, 25), (20, 25)

bool is_overlap(pair<int, int> &p1, pair<int, int> &p2) {

}

void overlaps(vector<pair<int, int> > &I, vector<pair<int, int> > &J ) {
    // print pairs of overlapping ranges
    vector<pair<int, int> >::iterator i, j;
    int start_index = 0;

   for (i = I.begin(); i != I.end(); i++) {
       j = binary_search(J, start_index, i->second);
       start_index = j.index
       while(j) {
           if (!is_overlap(*i, *j))
               break;
           print(*i, *j);
           j--;
       }
   }
}


binary_search(J, start_index, r) {
  for (j = start_index; ) {

  }
}

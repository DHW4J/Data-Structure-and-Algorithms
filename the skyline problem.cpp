vector<vector<int>> getBuildingSkyline(vector<vector<int>> &arr) {
  int n = arr.size();
  vector<vector<int>> v;
  for(int i=0;i<n;++i){
    v.push_back({arr[i][0],0-arr[i][2]});
    v.push_back({arr[i][1],arr[i][2]});
  }
//   sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//     return a.first != b.first ? a.first < b.first : a.second < b.second;
//   });
  sort(v.begin(), v.end());
  //sort(v.begin(),v.end());
  vector<vector<int>> ans;
  multiset<int> pq{0};
  
  int ongoingHeight = 0;
  for(int i=0;i<v.size();++i){
      int currentPoint = v[i][0];
      int currentHeight = v[i][1];    
      
      if(currentHeight<0){
          pq.insert(abs(-currentHeight));
      }else{
          pq.erase(pq.find(currentHeight));
      }
      auto pqTop = *pq.rbegin();
      if(ongoingHeight!=pqTop){
          ongoingHeight = pqTop;
          ans.push_back({currentPoint, ongoingHeight});
      }
      
      
  }
  return ans;
}

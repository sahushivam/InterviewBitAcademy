int maxChunksToSorted(vector<int>& arr) {
    
    if(arr.size()==0)
        return 0;
    
    stack<int> st;
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        
        if(arr[i]>=st.top()){
            st.push(arr[i]);
            continue;
        }
        int temp = st.top();
        while(!st.empty() && arr[i] < st.top())
            st.pop();
        
        st.push(temp); 
    }
    return st.size();
}
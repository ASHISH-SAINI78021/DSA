/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/



void insertElement(stack<int> &st, int element){
    // base case 
    if (st.empty() || st.top() <= element){
        st.push(element);
        return ;
    }
    
    // solution for one case
    int top = st.top(); st.pop();
    insertElement(st, element);
    st.push(top);
}
void sortStack(stack<int> &st){
    // base case
    if (st.empty()) return ;
    
    // solution for one case
    int element = st.top();st.pop();
    sortStack(st);
    insertElement(st, element);
}
void SortedStack ::sort() {
    if (s.empty()) return ;
    sortStack(s);
}













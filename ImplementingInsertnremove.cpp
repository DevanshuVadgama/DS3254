#include <iostream>

using namespace std;

class MyArray {
  private:
    int* _arr;
    int _capacity;
    int _size;

  public:
    MyArray(int capacity) {
      _arr = new int[capacity];
      _capacity = capacity;
      _size = 0;
    }

    ~MyArray() {
      delete [] _arr;
    }

    int length() {
      return _size;
    }

    int elementAt(int i) {
      return _arr[i];
    }

    void replace(int i, int x) {
      _arr[i] = x;
    }

    void append(int x) {
      _arr[_size] = x;
      _size++;
    }

    int removeLast() {
      int ret = _arr[_size - 1];
      _size--;
      return ret;
    }

    void insert(int i, int x) {
      _size++;
      for(int k = _size-1; k>=i;k--){
        if(k==i){
          _arr[i] = x;
          break;
        }
        _arr[k] = _arr[k-1];
      }
    }

    int remove(int i) {
      int value = _arr[i];
      for(int k = i; k<_size;k++){
        _arr[k] = _arr[k+1];
      }
      _size--;
      return value;
    }

    friend ostream& operator<<(ostream& out, const MyArray& arr){
      out << "[ ";
      for(int i = 0 ;i<arr._size;i++){
        out << arr._arr[i] << " ";
      }
      out << "]" << '\n';
      return out;
    }
};

int main(){
  int n;
  cout<<"give array size"<<endl;
  cin>>n;
     MyArray arr(n);
  for(int i=0; i<n; i++){
      arr.append(2*i);
}
cout<<arr;
int k;
int x;
int l;
cout<<"index to insert"<<endl;
cin>>k;
cout<<"number to insert";
cin>>x;
cout<<"which index to remove";
cin>>l;
arr.insert(k,x);
arr.remove(l);
cout<<"Ouput after inserting "<< arr;

}


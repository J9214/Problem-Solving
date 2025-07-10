    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string a, b;
        int carry = 0, i = 0, j = 0, k = 0;
        bool check = true;

        cin >> a >> b;

        int size = max(a.size(), b.size()) + 1;

        int *arr = new int[size]{};

        while(i < a.length())
            arr[i++] += (a[a.size() - i - 1] > '0' ? a[a.size() - i - 1] - '0' : 0);
        while(j < b.length())
            arr[j++] += (b[b.size() - j - 1] > '0' ? b[b.size() - j - 1] - '0' : 0);
        while(k < size){
            check = true;
            if(arr[k] >= 10) {
                arr[k++] -= 10;
                arr[k]++;
                check = false;
            }
            else k++;
        }

        for(int i = size - 1; i >= 0; i--){
            if(arr[i] == 0 && check) {
                continue;
            }
            else check = false;
            cout << arr[i];
        }

        return 0;
    }

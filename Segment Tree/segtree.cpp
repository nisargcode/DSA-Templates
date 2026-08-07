#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;
    vector<int> lazy;
    public:
    SGTree(int n){
        seg.assign(4*n + 1, 0);
        lazy.assign(4*n + 1, 0);
    }
    void build(int i , int l , int r , vector<int>&arr){
        if(l == r){
            seg[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, arr);
        build(2 * i + 2, mid + 1, r, arr);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int query(int start , int end , int i , int l , int r){
        if(l > end || r < start){
            return 0;
        }
        if(l >= start && r <= end){
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        int left = query(start, end, 2 * i + 1, l, mid);
        int right = query(start, end, 2 * i + 2, mid+1, r);

        return left + right;
    }
    void update(int ind , int val , int i , int l , int r){
        if(l == r){
            seg[i] = val;
            return;
        }
            int mid = l + (r - l) / 2;
            if(ind <= mid){
                update(ind, val, 2 * i + 1, l, mid);
            }
            else{
                update(ind, val, 2 * i + 2, mid + 1, r);
            }
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    void rangeUpdate(int start , int end , int val , int i , int l , int r){
        if(lazy[i] != 0){
            seg[i] += (r - l + 1) * lazy[i];
            if(l != r){
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l > end || r < start){
            return;
        }
        if(l >= start && r <= end){
            seg[i] += (r - l + 1) * val;
            if(l != r){
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        rangeUpdate(start, end, val , 2 * i + 1, l, mid);
        rangeUpdate(start, end, val, 2 * i + 2, mid+1, r);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int rangeQuery(int start , int end , int i , int l , int r){
         if(lazy[i] != 0){
            seg[i] += (r - l + 1) * lazy[i];
            if(l != r){
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l > end || r < start){
            return 0;
        }
        if(l >= start && r <= end){
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        int left = rangeQuery(start, end, 2 * i + 1, l, mid);
        int right = rangeQuery(start, end, 2 * i + 2, mid+1, r);

        return left + right;
    }
};

int main() {

}
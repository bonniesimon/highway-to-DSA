//Solution not complete


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// Given
	int N = 3;
	int A[N] = {1, 0, 2};


	int jump, i=0;
	int last_index = N-1;
	int is_jumpable = 0;
	int prev;

	while(1){
		jump = A[i];
		if(i > last_index) break;
		if(i+jump > last_index){
			// cout << i << "-->";
			i = (i+jump) - (i+jump - last_index);
		}else if(i == last_index){
			// cout << i ;
			is_jumpable = 1;
			break;
		}else if(jump == 0 ){
			if(i-1 > prev){
				i--;
			}else{
				is_jumpable = 0;
				break;
			}
		}else{
			// cout << i << "-->";
			prev = i;
			i = i + jump;
		}
	}
	cout << "Answer : " << is_jumpable << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	int n;
// 	string s;cin >> s;
// 	n = s.size();
// 	int cubeta[ 2 ][ 2 ];
// 	memset( cubeta, 0, sizeof( cubeta ) );
// 	long long int par =  0, impar = 0, mask = 0;
// 	for(int i = 0;i < n; i++){
// 		mask = s[ i ]  - 'a';
// 		impar++;
// 		if( ( i + 1 ) % 2 == 0 ){
// 			impar += cubeta[ mask ][ 0 ];
// 			par += cubeta[ mask ][ 1 ];
// 			cubeta[ mask ][ 0 ]++;
// 			continue;
// 		}
// 		par += cubeta[ mask ][ 0 ];
// 		impar += cubeta[ mask ][ 1 ];
// 		cubeta[ mask ][ 1 ]++;
// 	}
// 	cout << par << " " << impar <<endl;
// 	return 0;
// }

#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	string ne, hay;
	int j = 0, count = 0, n, i, counter;

	while (cin >> n >> ne >> hay)
	{
		if (ne.length() > hay.length())
		{
			cout << endl;
		}
		if (ne.length() == hay.length())
		{
			if (hay == ne)
			{
				cout << 0 << endl;
			}
		}
		if (ne.length() < hay.length())
		{
			for (int k = 0; k <= (hay.length() - ne.length()); ++k)
			{
				i = k;
				counter = 0;
				for (j = 0; j < ne.length(); ++j)
				{
					if (hay[i] == ne[j])
					{
						++i;
						++counter;
						if (counter == n)
						{
							cout << i - n << endl;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
	}

	return 0;
}
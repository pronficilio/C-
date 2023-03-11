// problem: https://omegaup.com/arena/problem/IOI-2009-Mecho/

#include<iostream>
#include<algorithm>
#include<queue>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, s;
int x, y, x2, y2;
char mapa[802][802];

int TB[802][802], TM[802][802];
int mov[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool valideBee( int r, int c ){
	if( !r || !c || r > n || c > n )
		return false;
	if( TB[r][c] != -1 )
		return false;
	if( mapa[r][c] == 'T' || mapa[r][c] == 'D' )
		return false;
	return true;
}

void BeeFS(){

	queue< pair< int, int > > Q;
	pair< int, int > act;
	int r, c;

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= n; j++ ){
			if( mapa[i][j] == 'H' )
				Q.push( make_pair( i, j ) );
			else
				TB[i][j] = -1;
		}

	while( !Q.empty() ){
		act = Q.front();
		Q.pop();
		for( int i = 0; i < 4; i++ ){
			r = act.first + mov[i][0]; c = act.second + mov[i][1];
			if( valideBee( r, c ) ){
				TB[r][c] = TB[act.first][act.second] + s;
				Q.push( make_pair( r, c ) );
			}
		}
	}

}

bool valideMecho( int r, int c, int t ){

	if( !r || !c || r > n || c > n )
		return false;
	if( TM[r][c] != -1 )
		return false;
	if( mapa[r][c] == 'T' )
		return false;
	if( mapa[r][c] == 'D' )
		return true;
	if( t >= TB[r][c] )
		return false;
	return true;
}

bool possible( int wait ){

	queue< pair< int, int > > Q;
	pair< int, int > act;
	int r, c, t;

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= n; j++ )
			TM[i][j] = -1;
	TM[x][y] = wait * s;
	if( TB[x][y] <= TM[x][y] )
		return false;
	Q.push( make_pair( x, y ) );

	while( !Q.empty() ){
		act = Q.front();
		Q.pop();
		t = TM[act.first][act.second] + 1;
		for( int i = 0; i < 4; i++ ){
			r = act.first + mov[i][0]; c = act.second + mov[i][1];
			if( valideMecho( r, c, t ) ){
				TM[r][c] = t;
				Q.push( make_pair( r, c ) );
			}
		}
	}

	return TM[x2][y2] != -1;

}

int main(){

	optimizar_io
	cin >> n >> s;
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= n; j++ ){
			cin >> mapa[i][j];
			if( mapa[i][j] == 'M' ){
				x = i; y = j;
			}
			if( mapa[i][j] == 'D' ){
				x2 = i; y2 = j;
			}
		}
	BeeFS();
	/*for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= n; j++ )
			cout << TB[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/

	if( !possible( 0 ) ){
		cout << "-1\n";
		return 0;
	}

	int b = 0, e = 640000, m;
	while( b != e ){
		m = (b + e) / 2 + 1;
		if( possible( m ) )
			b = m;
		else
			e = m - 1;
	}
	cout << b << "\n";

	return 0;

}
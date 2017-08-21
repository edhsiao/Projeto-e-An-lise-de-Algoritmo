#include <iostream>

using namespace std;

void permuta(string s, int indice, int s_size,
			 int proibidos[], int pos_proibidos[], int total_size)
{
	if(indice == s_size)
	{
		int index_string = 0;

		for(int i = 0; i < total_size; i++)
		{
			int flag_proibido = 0;

			for(int j = 0; j < total_size - s_size; j++)
			{
				if(i == pos_proibidos[j])
				{
					cout << proibidos[j] + 1 << " ";
					flag_proibido = 1;
					break;
				}
			}

			if(!flag_proibido)
			{
				int num = (int)(s[index_string] - '0') + 1 ;

				cout << num << " ";
				index_string++;
			}
		}
		cout << endl;
	}
	else
	{
		for(int i = indice; i < s_size; i++)
		{
			swap(s[i], s[indice]);
			permuta(s, indice + 1, s_size,
					proibidos, pos_proibidos, total_size);
		}
	}
}

int main()
{
	int N, M;

	cin >> N >> M;

	int numeros[N];
	int proibidos[M];
	int pos_proibidos[M];

	for(int i = 0; i < N; i++)
		numeros[i] = 0;

	for(int i = 0; i < M; i++)
	{
		int lin, col;

		cin >> lin >> col;

		proibidos[i] = lin - 1;
		pos_proibidos[i] = col - 1;
		numeros[lin - 1] = 1;
	}

	string s;

	for(int i = 0; i < N; i++)
	{
		if(!numeros[i])
			s.push_back((char)i + '0');
	}
    cout<<"S: " << s << endl;
	permuta(s, 0, N - M, proibidos, pos_proibidos, N);

	return 0;
}
//
//-----
//int main()
//{
//	int N;
//
//	cin >> N ;
//
//	int numeros[N];
//
//    for(int i = 0; i < N; i++)
//        cin>>numeros[i];
//	string s;
//
//	for(int i = 0; i < N; i++)
//	{
//		if(!numeros[i])
//			s.push_back((char)i + '0');
//	}
//
//    cout << s << " ";
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main ()
//{
//   string str1("A");
//  string str2("B");
//  string str3("G");
//  string str4;
//
//
//  cout << "  str3: " << str3 << "\n\n";
//
//  // Use push_back() to add characters to str4.
//  for(char ch = 'A'; ch <= 'z'; ++ch)
//    str4.push_back(ch);
//  cout << "str4 after calls to push_back(): " << str4 << endl;
//  cout << "Size and capacity of str4 is now " << str4.size() << " " << str4.capacity() << "\n\n";
//int N = 5;
//string s;
//int numeros[N];z
//for(int i = 0; i < N; i++)
//		numeros[i] = 0;
//for(int i = 0; i < N; i++)
//	{
//		if(!numeros[i])
//			s.push_back((char)i +48);
//	}
//	cout << s << endl;
//}

//int main()
//{
//
//int N = 5;
//string s;
//int numeros[N];
//for(int i = 0; i < N; i++)
//		numeros[i] = 0;
//for(int i = 0; i < N; i++)
//	{
//		if(!numeros[i])
//			s.push_back((char)i +48);
//	}
//	cout << s << endl;
//}

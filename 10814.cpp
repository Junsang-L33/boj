#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef struct Person{
	int age;
	string name;
	
	bool operator<(const Person &other) const{
		return age < other.age;	
	}
}Person;

int main(int argc, char* argv[]){

	int N;
	cin>>N;

	vector<Person> people(N);
	for(int i=0; i<N; ++i){
		cin >> people[i].age >> people[i].name;	
	}
	stable_sort(people.begin(), people.end());

	for(const auto &p : people){
		cout<<p.age << ' ' << p.name << '\n';	
	}

	return 0;
}

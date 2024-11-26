#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]){
	int card_num; //상근이가 가진 숫자개수
	scanf(" %d", &card_num);

	vector<int> have_card_num(card_num);
	for(int i = 0; i<card_num; i++){
		scanf(" %d", &have_card_num[i]);	
	}

	sort(have_card_num.begin(), have_card_num.end());
	
	int question_num;
	scanf(" %d", &question_num);

	for(int i=0; i<question_num; i++){
		int question_card;
		scanf(" %d", &question_card);
		
		auto lower = lower_bound(have_card_num.begin(), have_card_num.end(), question_card);
		auto upper = upper_bound(have_card_num.begin(), have_card_num.end(), question_card);
		
		int count = upper - lower; 
				// lower_bound는 target값보다 이상인 값의 위치를 찾고, upper_bound는 초과인 값의 위치를 
			 //찾기때문에 upper - lower 하면 몇개가 있는지 알 수 있음. 
		printf("%d ", count);			
		
	}
		
	return 0;
}

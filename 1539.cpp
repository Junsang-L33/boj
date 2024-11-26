#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

map<int, int> heights;

int main(int argc, char* argv[]){
	int n;
	int data=0;
	long long total = 0; //총 높이 저장할 변수

	scanf("%d", &n); //노드개수

	for(int i=0; i<n; i++){
		scanf("%d", &data); //노드값 입력

		auto iter = heights.lower_bound(data); //lower_bound는 값보다 크거나 같은 첫번째 원소의 반복자 반환
		long long left=0, right=0; //이웃의 높이 저장할 변수
		
		if(iter != heights.begin()){ //왼쪽이웃이 있는경우
				//iter가 begin이 아니라면, 왼쪽이웃이 존재한다는 뜻
			auto left_iter = iter;
			--left_iter; //왼쪽으로 한 칸 이동. lower_bound는 키값 이상인 위치를 반환하기때문에 왼쪽 이동시 -- 필요
			left = left_iter->second;	//(first 는 키값) 왼쪽이웃 높이 저장 second에는 높이 저장되어있음
		}	
	
		if(iter != heights.end()){ //오른쪽 이웃이 있는경우. iter가 end가 아니라면 오른쪽이웃이 있다는뜻.
			right = iter->second;	//오른쪽 이웃 높이 저장
		}	
		
		heights[data]	= max(left, right)+1; //왼쪽과 오른쪽 중 높이가 더 큰 값에 1을 더해서 현재노드높이로 설정
	
		total += heights[data];	
	}
	printf("%lld\n", total);

	return 0;
}

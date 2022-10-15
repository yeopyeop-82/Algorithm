#include <iostream>

using namespace std;

int partition (int s, int e, int A[])
{
    int pivot, left, right;
    left = s + 1; // left는 시작지점 + 1
    right = e; // right는 끝지점
    pivot = A[s];
    // 두개의 인덱스를 가지고 양 끝에서 탐색을 시작한다.

    while (left <= right) {// left 가 오른쪽보다 작거나 같을때 !!!
        while((A[right] >= pivot) && (left <= right))
            right--; // right가 pivot 보다 작은 경우 pass 계속 탐색 && left가 여전히 right보다 작거나 같은경우 (안엇갈린다.)
        while((A[left] <= pivot) && (left <= right))
            left++; // left가 pivot 보다 큰 경우 pass
        
        if (left <= right)
            swap(A[left], A[right]); // 둘다 이제 걸린 상태죠 ?
            // 만약 left가 right 보다 여전히 작고 엇갈리지 않은 상태면
            // 두개를 swap 해줍니다.
    }
    swap(A[right], A[s]); // 엇갈렸으면 피봇과 right를 바꿔줍니다.
    return right; // 새로운 e 로 설정
}

void quick_sort (int s, int e, int A[])
{
    if (s >= e)
        return; // 새로운 pivot을 찾음
    int m = partition(s, e, A);
    quick_sort(s, m-1, A);
    quick_sort(m+1, e, A); 
    // 두개로 쪼갠다.
    //divide 과정은 있지만 다시 합치는 과정은 없음
    // 가변 divide
}

int main(void)
{
    int A[] = {4, 7, 3, 10, 8, 5, 1, 2, 9, 6};

    quick_sort(0, 9, A);

    for (int i = 0; i<10; i++){
        cout << A[i];
    }

    return 0;

}
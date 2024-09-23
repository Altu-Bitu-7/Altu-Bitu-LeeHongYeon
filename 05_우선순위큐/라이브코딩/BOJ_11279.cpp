#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int pop(vector<int>& heap){
//     int top = heap[1]; //1번 인덱스에 있는 것이 루트
    
//     //가장 마지막에 인덱스에 있는 값을 루트에 넣는다
//     heap[1] = heap[heap.size() - 1];
//     heap.pop_back(); //가장 마지막 원소 빼기

//     //더 큰 자식 찾기
//     int parent = 1; //맨 처음 부모는 루트
//     int child = 2; //왼쪽 자식

//     while(child < heap.size()){
//         if(child + 1 < heap.size() && heap[child] < heap[child + 1]){ //오른쪽 자식이 사이즈보다 큰지, 왼쪽 자식이 오른쪽 자식보다 작은 경우
//             child += 1; //오른쪽 자식과 부모를 비교
//         }
//         if(heap[child] > heap[parent]) {//자식이 부모보다 큰 경우 
//             swap(heap[child], heap[parent]);

//             //다음 자식 노드 탐색
//             parent = child;
//             child *= 2;
//         } 
//         else{
//             break; //부모가 자식보다 작지 않을 경우
//         }
//     }

    
//     return top;
// }

// void push(int x, vector<int>& heap){
//     int idx = heap.size(); //새로운 값이 추가될 인덱스
//     heap.push_back(x);

//     //부모와 비교하여 부모 노드보다 자식 노드가 크다면 swap
//     // 루트 노트(인텍스 1)  자식 노드    부모 노드
//     while(idx > 1 && heap[idx] > heap[idx/2]){
//         swap(heap[idx], heap[idx/2]);
        
//         //다음 부모 탐색
//         idx /= 2; 
//     }
//     return;

// }

// bool isEmpty(vector<int>& max_heap){
//     return max_heap.size() == 1; //0번 인덱스만 있으면 비어있는 것임
// }

int main(){
    
    //입력
    // 입출력 속도를 증가시키는 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    priority_queue<int> max_heap;

    //vector<int> max_heap;
    //max_heap.push_back(0); //0번 인덱스는 비어있으니 아무 값이나 넣어도 됨
    cin >> n;

    // while(n--){
    //     cin >> x;

    //     //x가 0이라면 최대 힙에서 가장 큰 값 출력하고 제거
    //     if (x == 0){
    //         //최대 힙이 비었다면 0출력
    //         if(isEmpty(max_heap)){
    //             cout << "0\n";
    //             continue;
    //         }
    //         cout << pop(max_heap) << "\n";
    //     }
    //     //x가 자연수라면 최대 힙에 추가
    //     else{
    //         push(x, max_heap);
    //     }
    // }

        while(n--){
        cin >> x;

        //x가 0이라면 최대 힙에서 가장 큰 값 출력하고 제거
        if (x == 0){
            //최대 힙이 비었다면 0출력
            if(max_heap.empty()){
                cout << "0\n";
                continue;
            }
            cout << max_heap.top() << "\n";
            max_heap.pop();
        }
        //x가 자연수라면 최대 힙에 추가
        else{
            max_heap.push(x);
        }
    }
}
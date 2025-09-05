#include <bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    Node* pLeft;
    Node* pRight;
    Node(int n): num(n), pLeft(nullptr), pRight(nullptr) {}
};

struct Tree{
    Node* pHead;
    int num_left;   // head 기준 왼쪽 개수
    int num_right;  // head 기준 오른쪽 개수
    Tree(): pHead(nullptr), num_left(0), num_right(0) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int M; 
        cin >> M;

        Tree myTree;
        vector<int> meds;
        meds.reserve((M + 1) / 2);

        for (int i = 0; i < M; ++i) {
            int value; 
            cin >> value;
            Node* p = new Node(value);

            if (myTree.pHead == nullptr) {
                myTree.pHead = p;
            } else {
                Node* myP = myTree.pHead;

                if (value < myP->num) {
                    ++myTree.num_left;
                    // 왼쪽으로 내려가며 삽입 위치 찾기
                    while (myP->pLeft != nullptr && myP->pLeft->num > value) {
                        myP = myP->pLeft;
                    }
                    if (myP->pLeft == nullptr) {
                        // 맨 왼쪽에 붙임
                        p->pRight = myP;
                        myP->pLeft = p;
                    } else {
                        // myP->pLeft 와 myP 사이에 끼우기
                        p->pLeft = myP->pLeft;
                        myP->pLeft->pRight = p;
                        p->pRight = myP;
                        myP->pLeft = p;
                    }
                } else {
                    ++myTree.num_right;
                    // 오른쪽으로 내려가며 삽입 위치 찾기
                    while (myP->pRight != nullptr && myP->pRight->num < value) {
                        myP = myP->pRight;
                    }
                    if (myP->pRight == nullptr) {
                        // 맨 오른쪽에 붙임
                        p->pLeft = myP;
                        myP->pRight = p;
                    } else {
                        // myP 와 myP->pRight 사이에 끼우기
                        p->pRight = myP->pRight;
                        myP->pRight->pLeft = p;
                        p->pLeft = myP;
                        myP->pRight = p;
                    }
                }
            }

            // 균형 맞추기: head를 좌/우로 한 칸 이동
            if (myTree.num_left > myTree.num_right) {
                myTree.pHead = myTree.pHead->pLeft;
                --myTree.num_left;
                ++myTree.num_right;
            } else if (myTree.num_right > myTree.num_left + 1) {
                // 이 케이스가 생기지 않도록 하려면 삽입 분기/조건을 더 정교화해야 하지만,
                // 안전을 위해 한 번 더 체크해 둠
                myTree.pHead = myTree.pHead->pRight;
                ++myTree.num_left;
                --myTree.num_right;
            }

            // (i+1)이 홀수일 때 중앙값 저장
            if (i % 2 == 0) meds.push_back(myTree.pHead->num);
        }

        // 출력 형식
        cout << meds.size() << '\n';
        for (size_t i = 0; i < meds.size(); ++i) {
            cout << meds[i];
            if ((i + 1) % 10 == 0 || i + 1 == meds.size()) cout << '\n';
            else cout << ' ';
        }

        // new한 노드 delete는 생략(채점 종료 시 OS 회수)
    }
    return 0;
}

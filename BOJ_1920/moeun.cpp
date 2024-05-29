#include<iostream>
#include<algorithm>
#define SWAP(a, b, t) ((t) = (a), (a)=(b), (b) = (t))

using namespace std;

int n, m;
int lis[100000], lst[100000];

// ���� �����ϴٰ� �����ϴ� ������
// ������ �� ��α׺��鼭 ����
void qksort(int* arr, int s, int e) {
	// �������� �������� ũ�ų� ���� = ���ĳ����ٴ¶�
	if (s >= e) return;

	int p = arr[s]; // �ǹ��� ����Ʈ �������� �ִ¼���
	int left = s; // �ι�° ������ �񱳽���
	int right = e; // �����ʳ����� �񱳽���
	int t; // ���ҿ� temp

	while (left < right) // �迭 �ε����� �����ϱ� ��������
	{
		while (arr[left] <= p && left < e) { // �ǹ����� �������� �н�, ū�������� ����
			left++;
		}
		while (arr[right] >= p && right > s) { // �ǹ����� ū���� �н�, ������ ������ ����
			right--;
		}

		if (left < right) { // left, right�� ������ ���� �������� ����
			// �ǹ����� ū�� ���ʿ� �ִ¼�
			// �ǹ����� ������ �����ʿ� �ִ¼� ���� �ٲ�
			SWAP(arr[left], arr[right], t);
		}
	}
	// �ǹ����� �������� ���� ����, ū���� ���� �����ʿ� ����
	// �μ��� ���������� ���� right(left�� ����Ű�� �ִ� ��)�� �ǹ��̶� �ٲ�
	SWAP(arr[s], arr[right], t);

	//�ǹ� ���ʿ����� �ٽ� ����
	qksort(arr, s, right - 1);
	qksort(arr, right + 1, e);

	return;
}

int bsearch(int* arr, int t, int s, int e) {
	// ��ã�� �����ٲ�� ��Ȳ
	if (s > e) return 0;

	int mid = (s + e) / 2; // �ݶ�

	if (arr[mid] == t) // ��ġ
		return 1;
	else if (t < arr[mid]) // Ÿ�ٺ��� ���� ũ�� ������ ã�ƾ���
		return bsearch(arr, t, s, mid - 1);
	else // Ÿ�ٺ��� ������� ������ Ž��
		return bsearch(arr, t, mid + 1, e);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lis[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> lst[i];
	}

	sort(lis, lis + n);

	//qksort(lis, 0, n - 1);

	//for (int i = 0; i < n; i++) {
	//	cout << lis[i] << " ";
	//}

	for (int i = 0; i < m; i++) {
		int ans = bsearch(lis, lst[i], 0, n - 1);
		cout << ans << endl;
	}

	return 0;
}
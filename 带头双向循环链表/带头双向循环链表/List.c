#include "List.h"

//��ʼ������
void ListInit(List* plist){
	assert(plist);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

//����,�ͷź���
void ListDestroy(List* plist){
	ListNode* tmp = plist->_head->_next;
	while (tmp != plist->_head){
		tmp->_next->_prev = tmp->_prev;
		tmp->_prev->_next = tmp->_next;
		free(tmp);
		tmp = plist->_head->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

//β��
void ListPushBack(List* plist, LTDataType x){
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_prev->_next = cur;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
	
}

//βɾ
void ListPopBack(List* plist){
	ListNode* tmp = plist->_head->_prev;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

//ͷ��
void ListPushFront(List* plist, LTDataType x){
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	
	plist->_head->_next->_prev = cur;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}

//ͷɾ
void ListPopFront(List* plist){
	ListNode* tmp = plist->_head->_next;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

//��ӡ����
void ListPrint(List* plist){
	ListNode* cur;
	printf("head<-->");
	for (cur = plist->_head->_next; cur; cur = cur->_next){
		printf("%d<-->", cur->_data);
	}
	printf("<-->head\n");
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ShoppingItem {
	char name[50];
	int quantity;
	struct ShoppingItem *next;
}; 
struct ShoppingItem* shoppingList = NULL; // 新建链表头指针，初始化购物清单为空
//1. 添加商品到购物清单：
void addItem(char itemName[],int itemQuantity){
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	strcpy(newItem->name, itemName);//新结点赋值
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	struct ShoppingItem *p = shoppingList;
	if(shoppingList == NULL){
		shoppingList = newItem;
	}
	else{
		while(p->next != NULL){
			p = p->next;
		}
		p->next = newItem;
	}
	
}
//2. 从购物清单中移除商品：
void removeItem(char itemName[]){
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* previous = NULL;
	while(current != NULL){
		if(strcmp(current->name,itemName)==0){
			if(previous != NULL){
				previous->next = current->next;
			}
			else{
				shoppingList = current->next;
			}
			free(current);
			break;
		}
        previous = current;
        current = current->next;
	}
} 
//3. 查看购物清单：
void displayList(struct ShoppingItem *h){
	struct ShoppingItem* current = shoppingList;
	printf("购物清单：\n");
	while(h){
		printf("%s - 数量：%d\n",h->name,h->quantity);
		//填写一句 
		h = h->next;
	}
}
//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
	if (strcmp(current->name, itemName) == 0) {
//		此处填写一句。
		current->quantity = newItemQuantity;
		break;
	}
		current = current->next;
	}
}
//5. 清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
//		此处填写两句。
        struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		
		free(temp);
	}
}
//6. 计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
//		此处填写两句；
		total += current->quantity;
		current = current->next; 
	}
	return total;
}
//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("查找商品 \"%s\" ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		//	此处填写一句。
		current = current->next;
	}
	printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
		nextItem = current->next;
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				// 交换商品信息
				//此处填写 3 句；
				strcpy(tempName,nextItem->name);
				strcpy(nextItem->name,current->name);
				strcpy(current->name,tempName);
				
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		current = current->next;
	}
}
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	// 遍历到第一个购物清单的末尾
	// 补充循环语句；
	for(int i = 0; current->next != NULL; i++) {
		current = current->next;
	}
	// 将第二个购物清单连接到第一个清单的末尾
	current->next = *list2;
	*list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				// 如果要删除的是第一个节点
				struct ShoppingItem* temp = shoppingList;
				//填写一句；
				shoppingList = shoppingList->next;
				free(temp);
				if (!deleteAll)
					break;
			}
			else {
				// 如果要删除的不是第一个节点
				//填写一句；
				prev->next = current->next;
				free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}
int main(){
//	char itemName[50];
//	int itemQuantity;
//	scanf("%s",itemName);
//	scanf("%d",&itemQuantity);
//	addItem(itemName,itemQuantity);
//	print(shoppingList);
//	scanf("%s",itemName);
//	scanf("%d",&itemQuantity);
//	addItem(itemName,itemQuantity);
//	print(shoppingList);
	
	char name[50];
	int quantity,choice;
	printf("请先给这个清单添加一个商品及对应商品数量\n");
	
	scanf("%s%d",name,&quantity);
	addItem(name,quantity); 
	
	
	printf("之后，将根据你的选择来实现对应的操作\n");
	printf("操作列表：\n");
	printf("\n\
	1. 添加商品到购物清单\n\
	2. 从购物清单中移除商品\n\
	3. 查看购物清单\n\
	4. 修改购物清单中商品的数量\n\
	5. 清空购物清单\n\
	6. 计算购物清单中商品的总数量\n\
	7. 查找购物清单中的商品\n\
	8. 排序购物清单\n\
	9. 合并购物清单\n\
	10. 删除购物清单中的商品\n\
	");
	
	printf("请输入你想要执行的操作前对应的数字\n");
	
	while(scanf("%d", &choice)!=EOF){
		if(choice == 1){//执行1：添加商品 
			printf("请输入商品名字和对应的商品数量\n");
			scanf("%s%d",name,&quantity);
			addItem(name,quantity);
		}
		else if(choice ==2){//执行2：移除商品
			printf("请输入需要移除的商品名字\n");
		 	scanf("%s",name);
		 	removeItem(name);
			
		}
		else if(choice == 3){//执行3：查看清单
			displayList(shoppingList); 
		}
		else if(choice == 4){//执行4：修改商品数量
			printf("请输入需要修改数量的商品名字和修改后的数量\n");
			scanf("%s%d",name,&quantity);
			updateQuantity(name,quantity);
		}
		else if(choice == 5){//执行5：清空清单
			clearList(); 
		}
		else if(choice == 6){//执行6：计算商品总数量 
			quantity = totalQuantity();
			printf("商品总数量：%d\n",quantity);
		}
		else if(choice == 7){//执行7：查找商品 
			printf("请输入需要查找的商品名字\n");
			scanf("%s",name); 
			findItem(name);
		}
		else if(choice == 8){//执行8：排序清单 
			sortList(); 
		}
		else if(choice == 9){//执行9：合并清单
			struct ShoppingItem *list2 = NULL;//第二个清单样例 
			printf("请输入三个商品及数量用于第二个清单的样例\n");
			for(int i=0;i<3;i++){
				scanf("%s%d",name,&quantity);
				struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
				strcpy(newItem->name, name);//新结点赋值
				newItem->quantity = quantity;
				newItem->next = NULL;
				struct ShoppingItem *p = list2;
				if(list2 == NULL){
					list2 = newItem;
				}
				else{
					while(p->next != NULL){
						p = p->next;
					}
					p->next = newItem;
				}
			} 
			struct ShoppingItem *List1 = shoppingList;
			struct ShoppingItem *List2 = list2;
			
			mergeLists(&List1, &List2);
		}
		else if (choice == 10){//执行3：删除清单中的商品 
			printf("请输入需要删除的商品名字和是否删除全部改名字的商品\n");
			printf("/* 先输入名字，后输入1或0，1表示全部删除，0反之 */\n");
			scanf("%s",name);
			int dChoice = 0;
			scanf("%d",&dChoice);
			deleteItem(name,dChoice);
		} 
	}
	
	return 0;
} 
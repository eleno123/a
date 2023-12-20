#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct _stablo stablo;
typedef stablo* pozicija;
struct _stablo {

	int broj;
	pozicija livo;
	pozicija desno;
};

pozicija stvoricvor(int br);
pozicija dodaj(pozicija root, int br);
int inorder(pozicija root);
int postorder(pozicija root);
int preorder(pozicija root);


int main() {

	int  br = 0;
	char op;
	pozicija root = NULL;
	int novi = 0;
	printf("unesi br koji zelis dodat na pocetak\n");
	scanf("%d", &br);
	
	root = dodaj(root,br);

	

	while (1) {

		printf("unesi a za dodat novi br\n"
			"unesi i za inorder\n"
			"unesi p za postorder\n"
			"unesi r za preorder\n"
			"unesi k za kraj\n");
	scanf("%c", &op);
		
		switch (op) {

		case 'a':
			printf("unesi novi br\n");
			scanf("%d", &novi);
			dodaj(root, novi);
			break;

		case 'i':
			printf("inorder: ");
			inorder(root);
				break;

		case 'p':
			printf("postorder: ");
			postorder(root);
			break;

		case'r':
			printf("preorder: ");
			preorder(root);
			break;
		
		default:
			return 0;

		}

	

	}



	return 0;
}


pozicija stvoricvor(int br) {

	pozicija new = NULL;
	new = (pozicija)malloc(sizeof(stablo));

	if (!new) printf("greska u alok mem");

	new->broj = br;
	new->livo = NULL;
	new->desno = NULL;
	return new;
}

pozicija dodaj(pozicija root, int br) {

	if (root == NULL)
		return stvoricvor(br);

	if (br < root->broj)
		 root->livo = dodaj(root->livo, br);

	if (br >= root->broj)
	 root->desno = dodaj(root->desno, br);

	return root;
}

int inorder(pozicija root) {

	if (root != NULL) {

		inorder(root->livo);
		printf("%d ", root->broj);
		inorder(root->desno);
	}

	return 0;
}

int preorder(pozicija root) {

	if (root != NULL) {

		printf("%d ", root->broj);
		preorder(root->livo);
		preorder(root->desno);
	}

	return 0;
}

int postorder(pozicija root) {

	if (root != NULL) {

		postorder(root->livo);
		postorder(root->desno);
		printf("%d ", root->broj);
	}
	
	return 0;
}












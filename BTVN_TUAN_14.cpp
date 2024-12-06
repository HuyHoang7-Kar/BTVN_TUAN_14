#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc nút của cây
typedef struct Tnode {
    char c[10];            // Dữ liệu của nút (biểu thức hoặc ký tự)
    struct Tnode *left;    // Con trái
    struct Tnode *right;   // Con phải
} Tnode;

// Định nghĩa kiểu mới để dễ sử dụng
typedef struct Tnode treeNode;

// Hàm tạo một nút mới
treeNode* makeTree(const char *c) {
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ\n");
        exit(1);
    }
    strcpy(newNode->c, c);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Duyệt cây theo thứ tự trước (Pre-order)
void printPreorder(treeNode *T) {
    if (T != NULL) {
        printf("%s ", T->c);
        printPreorder(T->left);
        printPreorder(T->right);
    }
}

// Duyệt cây theo thứ tự giữa (In-order)
void printInorder(treeNode *T) {
    if (T != NULL) {
        if (T->left) printf("("); // In dấu ngoặc mở
        printInorder(T->left);
        printf("%s ", T->c);
        printInorder(T->right);
        if (T->right) printf(")"); // In dấu ngoặc đóng
    }
}

// Duyệt cây theo thứ tự sau (Post-order)
void printPostorder(treeNode *T) {
    if (T != NULL) {
        printPostorder(T->left);
        printPostorder(T->right);
        printf("%s ", T->c);
    }
}

int main() {
    // Xây dựng cây biểu thức thủ công
    treeNode *root = makeTree("+");

    // Nhánh trái của '+'
    root->left = makeTree("-");
    root->left->left = makeTree("*");
    root->left->left->left = makeTree("a");
    root->left->left->right = makeTree("5");

    root->left->right = makeTree("/");
    root->left->right->left = makeTree("*");
    root->left->right->left->left = makeTree("b");
    root->left->right->left->right = makeTree("^");
    root->left->right->left->right->left = makeTree("c");
    root->left->right->left->right->right = makeTree("6");
    root->left->right->right = makeTree("d");

    // Nhánh phải của '+'
    root->right = makeTree("*");
    root->right->left = makeTree("-");
    root->right->left->left = makeTree("h");
    root->right->left->right = makeTree("f");

    root->right->right = makeTree("^");
    root->right->right->left = makeTree("e");
    root->right->right->right = makeTree("^");
    root->right->right->right->left = makeTree("1");
    root->right->right->right->right = makeTree("2");

    // In cây theo các thứ tự duyệt
    printf("Duyet theo thu tu truoc (Pre-order): ");
    printPreorder(root);
    printf("\n");

    printf("Duyet theo thu tu giua (In-order): ");
    printInorder(root);
    printf("\n");

    printf("Duyet theo thu tu sau (Post-order): ");
    printPostorder(root);
    printf("\n");

    return 0;
}

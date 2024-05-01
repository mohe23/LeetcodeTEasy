// 二叉树的中序遍历

#include<stdio.h>
#include<stdlib.h>
//
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// 递归算法
void midtravel(struct TreeNode* root,int* a,int* count){//count-记录数组a中存储的元素个数。
    if(NULL!=root->left){//当前节点的左孩子不空
        midtravel(root->left,a,count);
    }
    a[(*count)] = root->val;// 保存当前结点的数据域中数据。
    (*count)++;
    if(NULL!=root->right){// 当前节点的右孩子不空
        midtravel(root->right,a,count);
    }

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {// 主功能函数。returnSize指向数组中元素个数。
    // returnsize不是已知的，而是需要一步一步计算的。接着我测试一下
    int*a = (int*)malloc(sizeof(int)*101);//该处不能用returnSize，该指针指向的存储空间初始值未知。
    if(NULL==root){// 结点数为0。
        a[0]='\0';
        (*returnSize)=0;
    }
    else// 结点数至少为1。
        midtravel(root,a,returnSize);

return a;
}

void Pri(int*t,int *size){// 输出数组中的数
    int i;
    if(0==(*size))//注意，当形参改变时，函数中调用的形参
        printf("数组长度为0！\n");
    else{
        printf("数组长度不为0！,数组元素如下：\n");
        for(i=0;i<(*size);i++)
            printf("%d ",t[i]);
    }

}

int main(){

   struct TreeNode s[4];
   s[0].val=12;
   printf("s[0]->val: %d\n",s[0].val);

return 0;
}
/*
int main(){
  int *le,*b;
  le = (int*)malloc(sizeof(int));//给指针le指向的元素分配存储空间。
  //b = (int*)malloc(sizeof(int));//给指针le指向的元素分配存储空间。

  struct TreeNode*s=(struct TreeNode*)malloc(sizeof(struct TreeNode));
  struct TreeNode*s1=(struct TreeNode*)malloc(sizeof(struct TreeNode));
  struct TreeNode*s2=(struct TreeNode*)malloc(sizeof(struct TreeNode));
  s->val = 12;s1->val = 23;s2->val = 56;
  s->left = NULL;s->right = s1;s1->left=s2;s1->right=NULL;s2->left=NULL;s2->right=NULL;
  //(*le) = 2;
  b = inorderTraversal(s,le);
  Pri(b,le);


return 0;
}
*/

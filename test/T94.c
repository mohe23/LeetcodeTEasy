// ���������������

#include<stdio.h>
#include<stdlib.h>
//
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// �ݹ��㷨
void midtravel(struct TreeNode* root,int* a,int* count){//count-��¼����a�д洢��Ԫ�ظ�����
    if(NULL!=root->left){//��ǰ�ڵ�����Ӳ���
        midtravel(root->left,a,count);
    }
    a[(*count)] = root->val;// ���浱ǰ���������������ݡ�
    (*count)++;
    if(NULL!=root->right){// ��ǰ�ڵ���Һ��Ӳ���
        midtravel(root->right,a,count);
    }

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {// �����ܺ�����returnSizeָ��������Ԫ�ظ�����
    // returnsize������֪�ģ�������Ҫһ��һ������ġ������Ҳ���һ��
    int*a = (int*)malloc(sizeof(int)*101);//�ô�������returnSize����ָ��ָ��Ĵ洢�ռ��ʼֵδ֪��
    if(NULL==root){// �����Ϊ0��
        a[0]='\0';
        (*returnSize)=0;
    }
    else// ���������Ϊ1��
        midtravel(root,a,returnSize);

return a;
}

void Pri(int*t,int *size){// ��������е���
    int i;
    if(0==(*size))//ע�⣬���βθı�ʱ�������е��õ��β�
        printf("���鳤��Ϊ0��\n");
    else{
        printf("���鳤�Ȳ�Ϊ0��,����Ԫ�����£�\n");
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
  le = (int*)malloc(sizeof(int));//��ָ��leָ���Ԫ�ط���洢�ռ䡣
  //b = (int*)malloc(sizeof(int));//��ָ��leָ���Ԫ�ط���洢�ռ䡣

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

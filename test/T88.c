// �ϲ�������������

#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {// �����ܺ���
    int i,j,k=0;

    if(0==m){// ����1����Ϊ0������2���Ȳ�Ϊ0
        for(i=0;i<n;i++)
            nums1[i]=nums2[i];//ֱ�ӽ�����2������Ԫ�ظ�ֵ������1�С�
    }
    else if(0==n)// ����1���Ȳ�Ϊ0������2����Ϊ0
        printf("����2��Ԫ�ظ���Ϊ0��\n");//��ʵ�������κβ�����ֻ��Ϊ���ڸ������£�����䡣
    else{// ����1������2���ȶ���Ϊ0
         int*nums3 = (int*)malloc(sizeof(int)*m);// ��������Ϊm������3���洢����1������Ԫ�ء�
         for(i=0;i<m;i++)// �Ȱ�����1��m�����ݴ洢������3��
             nums3[i]=nums1[i];
         for(i=0,j=0;i<m&&j<n;){// **�Ҿ�Ȼ������ѡ�j<n��д���ˡ�j<m����
             if(nums3[i]<nums2[j]){// ��ǰ����3��Ԫ��ֵС
                 nums1[k] = nums3[i];// ����СԪ�ظ�ֵ������1ָ��λ�ã�
                 i++;//����3���±��1������1�±겻�䡣
             }
             else{// ����2�ĵ�ǰԪ��ֵС
                 nums1[k]=nums2[j];// ������2�ĵ�ǰԪ�ظ�ֵ������1ָ��λ�á�
                 j++;//����2���±��1������1���±겻�䡣
             }
             k++;// ������ܻᱨ���ȱ��һ�£���
         }
         if(i==m){// ����3��ɨ����ϣ�����2δɨ�����
            for(j=j;j<n;j++){// ������2ʣ��Ԫ�����θ�ֵ������1��ʣ��λ�á�
                nums1[k]= nums2[j];
                k++;
            }
         }
         else{// ����2ɨ����ϣ�����3δɨ�����
             for(i=i;i<m;i++){
                 nums1[k] = nums3[i];
                 k++;
             }
         }
    }

}

/*
int main(){
   // printf("hello world!\n");
   char c[]="wqrtidjklmn";
   printf("%s",c);// ����ַ�����һ�ַ�����
   printf("\n");
  int a[]={4,0,0,0,0,0};//{1,2,3,0,0,0};
    int b[]={1,2,3,5,6};//{2,5,6};
    int i,la,lb,al,bl;
    la=6;lb=5;al=1;bl=5;
    merge(a,la,al,b,lb,bl);
    for(i=0;i<(al+bl);i++)
        printf("%d ",a[i]);
    //printf("hello world!\n");

return 0;
}
*/

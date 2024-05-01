// 合并两个有序数组

#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {// 主功能函数
    int i,j,k=0;

    if(0==m){// 数组1长度为0，数组2长度不为0
        for(i=0;i<n;i++)
            nums1[i]=nums2[i];//直接将数组2中所有元素赋值到数组1中。
    }
    else if(0==n)// 数组1长度不为0，数组2长度为0
        printf("数组2中元素个数为0！\n");//其实无须做任何操作，只是为了在该条件下，有语句。
    else{// 数组1，数组2长度都不为0
         int*nums3 = (int*)malloc(sizeof(int)*m);// 创建长度为m的数组3，存储数组1中所有元素。
         for(i=0;i<m;i++)// 先把数组1中m个数据存储到数组3。
             nums3[i]=nums1[i];
         for(i=0,j=0;i<m&&j<n;){// **我竟然在这里，把“j<n”写成了“j<m”。
             if(nums3[i]<nums2[j]){// 当前数组3中元素值小
                 nums1[k] = nums3[i];// 将较小元素赋值到数组1指定位置，
                 i++;//数组3的下标加1，数组1下标不变。
             }
             else{// 数组2的当前元素值小
                 nums1[k]=nums2[j];// 将数组2的当前元素赋值到数组1指定位置。
                 j++;//数组2的下标加1，数组1的下标不变。
             }
             k++;// 这个可能会报错，先标记一下！！
         }
         if(i==m){// 数组3先扫描完毕，数组2未扫描完毕
            for(j=j;j<n;j++){// 将数组2剩余元素依次赋值到数组1的剩余位置。
                nums1[k]= nums2[j];
                k++;
            }
         }
         else{// 数组2扫描完毕，数组3未扫描完毕
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
   printf("%s",c);// 输出字符串的一种方法！
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

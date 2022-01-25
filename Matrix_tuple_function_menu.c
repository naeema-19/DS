#include<stdio.h>

// write a menu driven program to enter 2 matrices in normal form, convert the 2 matrices to tuple form, transpose of the 2 matrices in tuple form, normal form of the transposed matrix from the tuple form, and sum of the 2 matrices which are represented in the tuple form and display the result in tuple form.
int r1, c1, n1=0, mat1[100][100]={0}, tup1[100][3]={0};
int r2, c2, n2=0, mat2[100][100]={0}, tup2[100][3]={0};
int trn1[100][100], tr1[100][3], trn2[100][100], tr2[100][3],e[100][3];
int tupsum[100][3], matrixsum[100][100];

int arrFilled = 0;

void showNormal(int mat[100][100], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void showTuple(int tup[100][3]){
    for(int i=0; i<=tup[0][2]; i++){
        printf("\n%d\t%d\t%d", tup[i][0], tup[i][1], tup[i][2]);
    }
}

void arrInput(){
    printf("Enter the no of rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the elements of the first matrix: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d", &mat1[i][j]);
            if(mat1[i][j])
                n1++;
        }
    }
    
    printf("Enter the no of rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the elements of the second matrix: \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d", &mat2[i][j]);
            if(mat2[i][j])
                n2++;
        }
    }

    printf("\n\nArray 1: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }


    printf("\n\nArray 2: \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    arrFilled=1;
}

void normal2tuple(int mat[100][100], int r, int c, int tup[100][3]){
    int i, j, k=1;
    tup[0][0] = r;
    tup[0][1] = c;
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            if(mat[i][j]){
                tup[k][0] = i;
                tup[k][1] = j;
                tup[k][2] = mat[i][j];
                k++;
            }
        }
    }
    tup[0][2] = k-1;
    showTuple(tup);
}

void sortTuple(int tr[100][3], int r){
    for(int i= 1; i <= r; i++){
        for(int j= i+1; j <= r; j++){
            if(tr[i][0] > tr[j][0]){
                int temp = tr[i][0];//1
                tr[i][0] = tr[j][0];//2
                tr[j][0] = temp;//3
                temp = tr[i][1];//1
                tr[i][1] = tr[j][1];//2
                tr[j][1] = temp;//3
                temp = tr[i][2];
                tr[i][2] = tr[j][2];
                tr[j][2] = temp;
            }
            if(tr[i][0] == tr[j][0]){
                if(tr[i][1] > tr[j][1]){
                int temp = tr[i][1];//1
                tr[i][1] = tr[j][1];//2
                tr[j][1] = temp;//3
                temp = tr[i][2];
                tr[i][2] = tr[j][2];
                tr[j][2] = temp;
                }
            }
        }
    }
    showTuple(tr);
}

void transposeTuple(int tr[100][3], int tup[100][3]){
    for(int k=0; k<=tup[0][2]; k++){
        tr[k][0] = tup[k][1];
        tr[k][1] = tup[k][0];
        tr[k][2] = tup[k][2];
    }
    sortTuple(tr, tup[0][2]);
}

void tuple2normal(int tr[100][3], int trn[100][100]){
    for(int k=1; k<=tr[0][2]; k++){
        trn[tr[k][0]][tr[k][1]] = tr[k][2];
    }
    for(int i = 0; i<tr[0][0]; i++){
        for(int j = 0; j<tr[0][1]; j++){
            if(!trn[i][j])
                trn[i][j] = 0;
        }
    }
    showNormal(trn, tr[0][0], tr[0][1]);
}

void matsum(int tup1[100][3],int tup2[100][3])
{
	int i,j,k,m,r1,r2;
	i=j=k=1;
	r1=tup1[0][2];
	r2=tup2[0][2];
	if(tup1[0][0]==tup2[0][0]&&tup1[0][1]==tup2[0][1])
	{
		e[0][0]=tup1[0][0];
		e[0][1]=tup1[0][1];
		while(i<=r1 && j<=r2)
		{
			if(tup1[i][0]==tup2[j][0])
			{
				if(tup1[i][1]==tup2[j][1])
				{
					if(tup1[i][2] + tup2[j][2]!=0)
					{
						e[k][0]=tup1[i][0];
						e[k][1]=tup1[i][1];
						e[k][2]=tup1[i][2] + tup2[j][2];
						k++;
					}
					i++; j++;
				}	
				else  if (tup1[i][1]<tup2[j][1])
				{
					e[k][0]=tup1[i][0];
					e[k][1]=tup1[i][1];
					e[k][2]=tup1[i][2];
					i++;k++;
				}
				else if (tup1[i][1]>tup2[j][1])
				{
					e[k][0]=tup2[j][0];
					e[k][1]=tup2[j][1];
					e[k][2]=tup2[j][2];
					j++;k++;
				}
			}
			else if(tup1[i][0]<tup2[j][0])
			{
				e[k][0]=tup1[i][0];
				e[k][1]=tup1[i][1];
				e[k][2]=tup1[i][2];
				i++;k++;
			}
			else if(tup1[i][0]>tup2[j][0])
			{
				e[k][0]=tup2[j][0];
				e[k][1]=tup2[j][1];
				e[k][2]=tup2[j][2];
				j++;k++;
			}
		}
		if(i<=r1)
		{
			for(m=i; m<=r1; m++)
			{	
				e[k][0]=tup1[m][0];
				e[k][1]=tup1[m][1];
				e[k][2]=tup1[m][2];
				k++;
			}
		}
		if(j<=r2)
		{
			for(m=j; m<=r2; m++)
			{
				e[k][0]=tup2[m][0];
				e[k][1]=tup2[m][1];
				e[k][2]=tup2[m][2];
				k++;
			}
		}
		e[0][2]=k-1;
	}
	else
	{
		printf("\n Cannot add these matrices\n");
	}
	for(int x=0;x<=e[0][2];x++)
	{
		for(int y=0;y<3;y++)
		{
			printf("%i\t",e[x][y]);		
		}
		printf("\n");	
	}
}

int main(){
    int choice;
    do {
        printf("\n\n\n\n\t\tTHE MATRIX PROGRAM\n\n");
        printf("1. Enter the 2 matrices in the normal form\n");
        printf("2. Convert the 2 matrices to tuple form\n");
        printf("3. Transpose the 2 matrices in tuple form\n");
        printf("4. Convert the transposed matrix from tuple form to normal form\n");
        printf("5. Show the sum of the 2 matrices which are represented in the tuple form\n");
        printf("6. Normal form of Sum Matrix\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: arrInput();
                    break;
            case 2: printf("Array 1: \n");
                    normal2tuple(mat1, r1, c1, tup1);
                    printf("\n\nArray 2: \n");
                    normal2tuple(mat2, r2, c2, tup2);
                    break;
            case 3: printf("Transpose of matrix 1: ");
                    transposeTuple(tr1, tup1);
                    printf("\n\nTranspose of matrix 2: ");
                    transposeTuple(tr2, tup2);
                    break;
            
            case 4: printf("\n\nTranspose of matrix 1: \n");
                    tuple2normal(tr1, trn1);
                    printf("\n\nTranspose of matrix 2: \n");
                    tuple2normal(tr2, trn2);
                    break;
            case 5: matsum(tup1, tup2);
                    break;
            case 6: printf("\n\nNormal form of Sum Matrix: \n");
                    tuple2normal(e, matrixsum);
                    break;
            case 7: printf("\n\n\n\n\t\tTHANK YOU\n\n\n\n");
                    break;
            default: printf("\n\n\n\n\t\tINVALID CHOICE\n\n\n\n");
        }
    }
    while(choice!=7);
}

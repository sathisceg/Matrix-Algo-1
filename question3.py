
import numpy as np

def houseHolder(inputList):

	inputArray = np.array(inputList)

	m,n = inputArray.shape

	A = inputArray

	U = np.zeros(shape=(m,n))
	# print m,n


	temp=[]

	# print inputArray
	# print
	# print inputArray[:,0:3]

	indetity_count = m

	for k in range(0,n):
		x=A[k:m,k]
		# print x 
		e = np.zeros(len(x))
		e[0]=1
		# print e

		u = np.sign(x[0])*np.linalg.norm(x)*e + x
		# print u

		if(np.linalg.norm(u)!=0):
			u = np.divide(u, u[0])

		udot = np.dot(u,u)

		temp.append(u)
		

		u = np.array(temp)

		temp=[]
		# print u
		uT = u.reshape((len(x), 1))

		#print uT

		uuT = np.dot(uT,u)
		# print umat
		# print uuT
		print 

		I = np.identity(indetity_count)
		
		t = 2/udot

		uuT = t*uuT

		
		if(indetity_count==2):
			H=I-uuT

			th = np.identity(3)
			# print H
			for i in range(k,n):
				for j in range(k,n):					
					th[i][j]=H[i-1][j-1]
				# print

			# print th
			
			H=th
		else:
			H=I-uuT
		
		indetity_count=indetity_count-1


		# print H
		# print


		A=np.matmul(H,A)

		# print A
		# print
		# print A[k+1:m,k]
		# print uT[k+1:m,:]


		if(len(uT[k+1:m,:])==0):
			# print uT[k:m,:] 
			# print uT
			# print "inside 2nd if"
			A[k+1:m,k]=uT[k:m,:] 
			# print A

			A[m-1][n-1]=-1*A[m-1][n-1]
			# print A
			break
		else:
			A[k+1:m,k]=uT[k+1:m,:].reshape(1,len(x)-1)
			# print A
		# break
	return A



inputList=[[2,-2,18],[2,1,0],[1,2,0]]

# inputList=[[1,1,-1],[1,-2,3],[2,3,1]]

B=[4,-6,7]
 
QR=houseHolder(inputList)

print QR

Q=np.identity(3)
		
for i in range(0,3):
	for j in range(0,i):
		Q[i][j]=QR[i][j]
		# print QR[i][j]
	print

# print Q


Y=[0,0,0]
X=[0,0,0]

# for(i=0;i<N;i++)
#   	{
#   		Y[i]=B[i];

#   		//printf("%lf\n",Y[i]);
#   		for(j=0;j<i;j++)
#   		{
#   			Y[i]-=L[i][j]*Y[j];
#   		}
#   		Y[i]/=L[i][i];

#   		//printf("%lf\n",Y[i]);
# 	}



for i in range(0,3):
	Y[i]=B[i]
	for j in range(0,i):
		Y[i]=Y[i]-Q[i][j]*Y[j]

	Y[i]=Y[i]/Q[i][i]
	# print Y[i]

# print Y

# for(i=N-1;i>=0;i--)
#   	{
#   		X[i]=Y[i];

#   		//printf("%lf\n",Y[i]);
#   		for(j=N-1;j>i;j--)
#   		{
#   			X[i]-=A[i][j]*X[j];
#   		}
#   		X[i]/=A[i][i];

#   		//printf("%lf\n",X[i]);
# 	}

# print "hello"
for i in range(2,-1,-1):
	X[i]=Y[i]
	for j in range(2,i,-1):
		X[i]=X[i]-QR[i][j]*X[j]
		# print QR[i][j]

	# print X[i],QR[i][i]

	X[i]=X[i]/QR[i][i]

	# print



print X
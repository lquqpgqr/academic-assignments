import matplotlib.pyplot as plot
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
import sklearn as skl

dataset = pd.read_csv('valorant_player_match_summery.csv')

print(dataset.head())
X = dataset[['agent','map','kill','death','avg_score']]
Y = dataset[['result']]

x_train,x_test,y_train,y_test = train_test_split(X, Y, test_size=0.66, random_state=42)

# Training a K Nearest Neighbors Classifier
knn=KNeighborsClassifier(n_neighbors=7).fit(x_train,y_train.values.ravel())

print('For K Nearest Neighbor Classifier:')
knn_predictions=knn.predict(x_test)
print('Actual Result:')
print(y_test.values.ravel())
print('Predected Result:')
print(knn_predictions)
print()
print('Accuracy: ',skl.metrics.accuracy_score(y_test,knn_predictions)*100)
print('Recall: ',skl.metrics.recall_score(y_test,knn_predictions)*100)
print('Precision: ',skl.metrics.precision_score(y_test,knn_predictions)*100)
print('f1:',skl.metrics.f1_score(y_test,knn_predictions)*100)

print()

# Training a Gaussian Naive Bayes Classifier
gnb=GaussianNB()
gnb.fit(x_train,y_train.values.ravel())

gnb_predictions=gnb.predict(x_test)

print('For Gaussian Naive Bayes Classifier:')
print('Actual Result:')
print(y_test.values.ravel())
print('Predected Result:')
print(gnb_predictions)
print()
print('Accuracy: ',skl.metrics.accuracy_score(y_test,gnb_predictions)*100)
print('Recall: ',skl.metrics.recall_score(y_test,gnb_predictions)*100)
print('Precision: ',skl.metrics.precision_score(y_test,gnb_predictions)*100)
print('f1:',skl.metrics.f1_score(y_test,gnb_predictions)*100)


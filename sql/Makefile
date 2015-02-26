foo = main.o my_db.o

mydb:$(foo)
	g++ -o mydb $(foo) -I /usr/local/mysql/include -L /usr/local/mysql/lib/ -lmysqlclient

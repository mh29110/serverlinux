objects=main.o ServerGame.o PlayerSession.o NetworkService.o \
	ServletManager.o ChatServlet.o ServerResource.o ServerNetwork.o \
	sql/my_db.o
edit:$(objects)
	g++ -g -o server $(objects) -I /usr/local/mysql/include/ -L /usr/local/mysql/lib/ -lmysqlclient

clean:
	rm -f *.o

edit:main.o ServerGame.o PlayerSession.o NetworkService.o ServletManager.o ChatServlet.o ServerResource.o ServerNetwork.o 
	g++ -g -o server main.o ServerGame.o PlayerSession.o NetworkService.o ServletManager.o ChatServlet.o ServerResource.o ServerNetwork.o 

clean: 
	rm -f *.o

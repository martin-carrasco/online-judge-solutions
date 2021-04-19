gcc=mpicxx

all: TSP_paralel_bb TSP_seq_bb TSP_seq
TSP_seq:
		gcc -o TSP_seq ../src/TSP_seq.cpp -L../include/

TSP_seq_bb:
		gcc -o TSP_seq_bb ../src/TSP_seq_bb.cpp -L../include/

TSP_paralel_bb:
		gcc -o TSP_paralel_bb ../src/TSP_parallel.cpp -L../include/
clean:
	 rm -f progs

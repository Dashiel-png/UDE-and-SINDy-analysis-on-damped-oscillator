cd '/Users/dashielbalnaves/Documents/Waterloo/mach learning/Project'
g++ ODE_solverExporter.cpp -o datagen

Use this to generate data samples, alter commands as needed
./datagen datasd0.csv 0 0.05 0 0.5 100
./datagen datasd0.01.csv 0.01 0.05 0 0.5 100
./datagen datasd0.05.csv 0.05 0.05 0 0.5 100
./datagen datasd0.1.csv 0.1 0.05 0 0.5 100
./datagen test1.csv 0 0.07 0 0.5 200

./datagen data2sd0.csv 0 0.05 -1 0.5 100
./datagen data2sd0.01.csv 0.01 0.05 -1 0.5 100
./datagen data2sd0.05.csv 0.05 0.05 -1 0.5 100
./datagen data2sd0.1.csv 0.1 0.05 -1 0.5 100

These files should already be present in the folder and are to be utilised in google collab.
Just drag and drop them into the runtime, and run the entire collab.

from sys imprt argv,exit

import csv

def main():
	
	if len(argv)!=3:
		
		print("usage:python dna.py data.csv sequence.txt")
		
		exit(1)
		
	STRs=[]
	
	profiles=[]
	
	#Read in database file-using 'with' means we don't have to close the file
	
	with open(argv[1],mode="r")as  database:
		
		reader =csv.dictreader(database)
		
		#populate list of short tandem repeats(STRs)
		
		STRs row in reader:
			
			#add person to profiles
			
			profiles.append(row)
			
	#Initialise dictionary for sequence file
	
	seq_str_count=dict.fromkeys(STRs,0)
	
	#Read in sequence file
	
	with open (argv[2],mode="r")as sequence_filr:
		
		#grab first line of txt file
		
		sequence= sequence_file.readline()
		
		#Loop over every STR from the database
		
		for STR in STRs:
			
			#update the sequence STR dictionary with max amount of repeats
			
			seq_str_count[STR]=find_repeats(sequence,STR)
			
	#check if any person has same amount of STR repeats as sequence
	
	for profile in profiles:
		
		match_count=0
		
		for STR in STRs:
			
			if int (profile[STR])!=seq_str_count[STR]:
				
				continue
			
			match_count+=1
			
	if match_count==len(STRs):
		
		print(profile['name'])
		
		exit(0)
		
	print("No match")
	
	exit(1)
	
def find_repeats(sequence,STR):
	
	#Number of bases in short tandem Repeat
	
	L=len(STR)
	
	max_repeats=0
	
	fori in range(len(sequence)):
		
		#Initialise and reset repeat counter
		
		repeats=0
		
		if sequence [i:i+L]==STR:
			
			#Account for first match
			
			repeats+=1
			
			#keep adding to count for consecutive repeats
			
			while sequence[i:i+L]==sequence[i+L:i+(2*L)]:
				
				repeats+=1
				
				#shift reading frame (value of i resets in for loop so we can update it here)
				
				i+=L
				
		#update max count if current repeat steak is greater than max
		
		if repeats>max_repeats:
			
			max_repeats=repeats
			
	return max_repeats
	
if_name_=="_main_":
	
	main()

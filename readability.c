int  is_word_end(c)

	return c ==" "
	
int is_sentance_end(c):
	
	return c =="."orc=="!"orc=="?"
	
def is_letter(c):
	return c.isalpha()

def coleman_liau_indax(letter_count,word_count,sentance_count):
	
	1=100*letter_count/word_count
	s=100*sentence_count/word_count
	result=(0.0588*1)-(0.296*s)-15.8
	result round(result)

text=get_sting("text:")

count=0

letter_count=0

word_count=0

sentance_count=0

for c in text:
	
	if is_word_end(c):
		
		word_count+=1
	
	elif is_sentence_end(c):
		
		sentance_count+=1
	
	elif is_letter(c):
		
		letter_count+=1

added count of last word
word_count+=1


index=coleman_liau_index(letter_count,word_count,sentence_count)

if index<1:
	
	print("Before grade 1")

elif index>16:
	
	print("grade 16+")

else:
	
	print(("grade { }").format(index))

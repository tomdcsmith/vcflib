#include "CachedRef.h"

namespace vcflib {
    
    
    CachedRef::CachedRef(FastaReference fastaRef) {
        this->fastaRef = fastaRef;
    }
    
    CachedRef::cacheSeq(string seqname){
        string sequence = fastaRef.getSequence(seqname);
        chromosomeMap.insert(std::map<string, string>::value_type(seqname, sequence));
    }
    
    CachedRef::getSequence(string seqname, int start, int length){
        
        string chrom_seq = chromosomeMap.find(seqname);
        
        length = min(length, chrom_seq.length - start + 1);
        if (start < 0 || length < 1) {
            //cerr << "Empty sequence" << endl;
            return "";
        }
        
        return s;
    }
    
    
}
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


#define NALLOC 1024 //最小分配单元

//只能在linux系统上工作，macos没用
typedef long Align; 
union header { 
	struct {
		union header *ptr; //指针
		unsigned size;
	} s;
	Align x; 
};

typedef union header Header;

static Header base;
static Header *freeptr = NULL;

void *QMalloc(unsigned nbytes);
Header *Qmorecore(unsigned nu);
void QFree(void *ap);


int main(){
	printf("sizeof Heaedr: %ld\n", sizeof(Header));
	base.x =110;
	int size=10;

	int nBlock= (size +sizeof(Header) -1 ) / sizeof(Header) + 1;

	printf("%d need nBlock: %d\n", size,nBlock);

	int *pint=QMalloc(sizeof(int) * 10);
	printf("pint: %p\n", pint);
	for(int i=1;i<10;i++){
		pint[i]=i;
	}

	for(int i=1;i<10;i++){
		printf("pint[%d]: %d\n", i, pint[i]);
	}
	QFree(pint);

	return 0;
};



void *QMalloc(unsigned nbytes){
    Header *p, *prevp;
    unsigned nunits;
    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1; 
    if ((prevp = freeptr) == NULL) { 
        base.s.ptr = freeptr = prevp = &base;
        base.s.size = 0; 
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) 
    { 
        if (p->s.size >= nunits) 
        {
            if (p->s.size == nunits) {
                prevp->s.ptr = p->s.ptr;
            }	
            else 
            { 
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freeptr = prevp;
            return (void *)(p+1);
        }

        if (p == freeptr) { /* wrapped around free list */
            if ((p = Qmorecore(nunits)) == NULL) {
				exit(-1);
                return NULL; /* none left */
            }
        }
    } 
}

void QFree(void *ap){
	Header *bp, *p;
	bp = (Header *)ap - 1; 

	for (p = freeptr; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
	{
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) 
			break; 
		if (bp + bp->s.size == p->s.ptr)
		{  
			bp->s.size += p->s.ptr->s.size;
			bp->s.ptr = p->s.ptr->s.ptr;
		}else{
		bp->s.ptr = p->s.ptr;
		}
		
		if (p + p->s.size == bp) 
		{
			p->s.size += bp->s.size; 
			p->s.ptr = bp->s.ptr;
		}else{
		p->s.ptr = bp;
		}
	}
		freeptr = p;
};

Header *Qmorecore(unsigned nu){
	char *cp;
	Header *up;
	if(nu < NALLOC){  //最小分配单元1024
		nu = NALLOC;
	}
	cp = (char *)sbrk(nu * sizeof(Header)); //最小分配1024 * 16
	if(cp == (char *)-1){
		return NULL;
	}

	up = (Header *)cp;
	up->s.size = nu;
	QFree((void *)(up+1));

	return freeptr;
};



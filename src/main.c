#include "../third_party/pdfio/pdfio.h"
#include "../third_party/pdfio/pdfio-private.h"
#include "../third_party/pdfio/pdfio-content.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  char* filename = "./test/programming_ground_up.pdf";
  pdfio_file_t *pdf = pdfioFileOpen(filename, NULL, NULL, NULL, NULL);

  if(pdf == NULL){
    return -1;
  }
 
  size_t num_pages = pdfioFileGetNumPages(pdf);
  for(size_t i = 0; i < num_pages; i++){
    pdfio_obj_t *page =  pdfioFileGetPage(pdf, i);

    if(page == NULL){
      continue;
    }

    size_t obj_number = pdfioObjGetNumber(page);


    for (size_t j = 0; j < obj_number; j++){
      pdfio_obj_t *sub_obj = pdfioFileGetObj(pdf,j);
      if(sub_obj != NULL){
        const char *dict = pdfioObjGetType(sub_obj);
        printf("%s", dict);

      }
    }

    return 0;

  }

  pdfioFileClose(pdf);
  return 0;
}

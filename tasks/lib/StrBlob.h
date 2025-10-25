#ifndef STRBLOB_H
#define STRBLOB_H

#include "Blob.h"
#include <string>

using StrBlob = Blob<string>;
using StrBlobPtr = BlobPtr<string>;

#endif // !STRBLOB_H
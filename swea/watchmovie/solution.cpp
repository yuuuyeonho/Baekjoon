#include <vector>

struct RESULT {
  int cnt;
  int IDs[5];
};

struct MOVIE {
  int mID;
  int mGenre;
  int mTotal;
  int viewers;
};

std::vector<int> user[1001];

void init(int N) { return; }

int add(int mID, int mGenre, int mTotal) { return -1; }

int erase(int mID) { return -1; }

int watch(int uID, int mID, int mRating) { return -1; }

RESULT suggest(int uID) {
  RESULT res;

  res.cnt = -1;

  return res;
}
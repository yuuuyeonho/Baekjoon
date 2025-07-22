#include <algorithm>
#include <cstring>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_USERS = 50005;

struct Movie {
  int mID;
  int genre;
  int total;
  int addedTime;
  bool deleted;
};

struct Watched {
  int time;
  int mID;

  bool operator<(const Watched& other) const { return time < other.time; }
};

struct RESULT {
  int cnt;
  int IDs[5];
};

int globalTime;
unordered_map<int, Movie> movieMap;
deque<Watched> userWatched[MAX_USERS];
unordered_set<int> userWatchedSet[MAX_USERS];

void init(int N) {
  movieMap.clear();
  globalTime = 0;
  for (int i = 0; i < MAX_USERS; ++i) {
    userWatched[i].clear();
    userWatchedSet[i].clear();
  }
}

int add(int mID, int mGenre, int mTotal) {
  if (movieMap.find(mID) != movieMap.end()) return 0;
  movieMap[mID] = {mID, mGenre, mTotal, ++globalTime, false};
  return 1;
}

int erase(int mID) {
  if (movieMap.find(mID) == movieMap.end() || movieMap[mID].deleted) return 0;
  movieMap[mID].deleted = true;
  return 1;
}

int watch(int uID, int mID, int score) {
  if (movieMap.find(mID) == movieMap.end() || movieMap[mID].deleted) return 0;

  Movie& movie = movieMap[mID];
  if (movie.total <= 0) return 0;

  movie.total--;

  userWatched[uID].push_back({++globalTime, mID});
  userWatchedSet[uID].insert(mID);

  // 유저가 이 장르를 시청한 총 점수와 횟수 누적
  int genre = movie.genre;
  userGenreScore[uID][genre].first += score;
  userGenreScore[uID][genre].second += 1;

  return 1;
}

RESULT suggest(int uID, int mGenre) {
  vector<Movie> candidates;

  for (auto it = movieMap.begin(); it != movieMap.end(); ++it) {
    int mID = it->first;
    const Movie& movie = it->second;

    if (movie.deleted) continue;
    if (movie.genre != mGenre) continue;
    if (userWatchedSet[uID].count(mID)) continue;

    candidates.push_back(movie);
  }

  sort(candidates.begin(), candidates.end(),
       [](const Movie& a, const Movie& b) {
         if (a.total != b.total) return a.total > b.total;
         return a.addedTime > b.addedTime;
       });

  RESULT res;
  res.cnt = 0;
  for (int i = 0; i < min(5, (int)candidates.size()); ++i) {
    res.IDs[i] = candidates[i].mID;
    res.cnt++;
  }

  return res;
}

// #include <vector>
// #include <algorithm>
// using namespace std;

// struct RESULT {
//   int cnt;
//   int IDs[5];
// };

// struct MOVIE {
//   int mID;
//   int mGenre;
//   int mTotal;
//   int viewers;
// };

// std::vector<MOVIE> movieList;
// std::vector<std::pair<int, int> > userTable[1001];

// void init(int N)
// {
//     return;
// }

// int add(int mID, int mGenre, int mTotal)
// {
//     for(int i=0; i<movieList.size(); ++i){
//         if (movieList[i].mID == mID) return 0;
//     }
//     movieList.push_back({mID,mGenre,mTotal,0});
//     return 1;
// }

// int erase(int mID)
// {
//     int viewers;
//     for(int i=0; i<movieList.size(); ++i){
//         if (movieList[i].mID == mID){
//             viewers = movieList[i].viewers;
//             movieList.erase(movieList.begin() + i);
//             return 1;
//         }
//     }
//     for(int i=0; i<1001; i++){
//         for(auto it = userTable[i].begin(); it !=  userTable[i].end();){
//             if(it->first == mID){
//                 it = userTable[i].erase(it);
//                 viewers--;
//             }
//             else ++it;
//         }
//         if(viewers == 0) break;
//     }
//     return 0;
// }

// int watch(int uID, int mID, int mRating)
// {
//     int index = 0;
//     bool isExist = false;

//     //실패하는 경우인지 확인
//     for(int i=0; i<userTable[uID].size(); ++i){
//         if (userTable[uID].at(i).first == mID) return 0;
//     }
//     for(int i=0; i<movieList.size(); ++i){
//         if(movieList[i].mID == mID){
//             index = i;
//             isExist = true;
//         }
//     }
//     if (!isExist) return 0;

//     // 로직
//     userTable[uID].push_back(make_pair(mID, mRating));
//     movieList[index].mTotal += mRating;
// }

// RESULT suggest(int uID) {
//   RESULT res;
//   res.cnt = 0;
//   int higherMovie = 0;
//   int higherScore = 0;
//   int cnt = 0;
//   for(int i=userTable[uID].size()-1; i>=0; --i){
//     if(userTable[uID].at(i).second > higherScore){
//         higherMovie = userTable[uID].at(i).first;
//         higherScore = userTable[uID].at(i).second;
//     }
//     cnt++;
//     if(cnt == 5) break;
//   }

//   if(userTable[uID].size() == 0){
//     for(no)
//   }

//   return res;
// }
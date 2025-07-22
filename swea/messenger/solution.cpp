// #include <vector>
// #include <cstring>
// using namespace std;

// struct Group {
//   int groupID;
//   int mNum;
//   vector<pair<int, bool> > uIDs;
// };

// struct Message {
//   char content[10];
//   int groupID;
// };

// vector<Group> groupList;
// vector<Message> userMessageBox[5001];

// void init(int N) {
//   userMessageBox->clear();
//   Group group;
//   groupList.push_back(group);
// }

// void createGroup(int groupID, int mNum, int uIDs[]) {
//   Group group;
//   group.groupID = groupID;
//   group.mNum = mNum;
//   for (int i = 0; i < mNum; ++i) {
//     group.uIDs.push_back(make_pair(uIDs[i], true));
//   }
//   groupList.push_back(group);
// }

// int sendMessage(int uID, int groupID, char mText[]) {
//   Group cur = groupList[groupID];
//   int mNum = cur.mNum;
//   int cnt = 0;

//   Message message;
//   strcpy(message.content, mText);
//   message.groupID = groupID;
//   for (int i = 0; i < mNum; ++i) {
//     if (cur.uIDs[i].first == uID) continue;
//     if (cur.uIDs[i].second == true) {
//       int curUser = cur.uIDs[i].first;
//       userMessageBox[curUser].push_back(message);
//       cnt++;
//     }
//   }
//   return cnt;
// }

// void setOnOff(int uID, int groupID) {
//   Group g = groupList[groupID];
//   for (int i = 0; i < g.uIDs.size(); ++i) {
//     if (g.uIDs[i].first == uID) {
//       if (g.uIDs[i].second == true) {
//         for (auto it = userMessageBox[uID].begin();
//              it != userMessageBox[uID].end();) {
//           if (it->groupID == groupID) {
//             it = userMessageBox[uID].erase(it);
//           } else {
//             ++it;
//           }
//         }
//         g.uIDs[i].second = false;
//       } else {
//         g.uIDs[i].second = true;
//       }
//       break;
//     }
//   }
// }

// int checkMsg(int uID, char mMsg[]) {
//   int ret = userMessageBox[uID].size();

//   if (ret != 0) {
//     mMsg = userMessageBox[uID].back().content;
//   }

//   userMessageBox[uID].clear();

//   return ret;
// }

#include <cstring>
#include <vector>

using namespace std;

const int MAX_USERS = 5001;
const int MAX_GROUPS = 501;

struct Message {
  int groupID;
  char text[10];  // 최대 9글자 + '\0'
};

// 유저의 받은 메시지함
vector<Message> inbox[MAX_USERS];

// 그룹 구성원 정보
vector<int> groupMembers[MAX_GROUPS];

// 유저별 그룹 설정 상태 (on/off)
bool userGroupSetting[MAX_USERS][MAX_GROUPS];

// init 함수 정의
void init(int N) {
  // 모든 유저 메시지함 초기화
  for (int i = 1; i <= N; ++i) {
    inbox[i].clear();
    for (int j = 1; j < MAX_GROUPS; ++j) {
      userGroupSetting[i][j] = false;
    }
  }

  // 모든 그룹 구성원 초기화
  for (int i = 1; i < MAX_GROUPS; ++i) {
    groupMembers[i].clear();
  }
}

void createGroup(int groupID, int mNum, int uIDs[]) {
  // 그룹 구성원 등록
  groupMembers[groupID].clear();  // 혹시 모를 중복 호출 대비 초기화
  for (int i = 0; i < mNum; ++i) {
    int uid = uIDs[i];
    groupMembers[groupID].push_back(uid);
    userGroupSetting[uid][groupID] = true;  // 그룹 설정 on
  }
}

void setOnOff(int uID, int groupID) {
  // 설정 토글 (on -> off, off -> on)
  userGroupSetting[uID][groupID] = !userGroupSetting[uID][groupID];

  // 받은 메시지 중 groupID에서 온 메시지 삭제
  vector<Message>& msgs = inbox[uID];
  vector<Message> filtered;

  for (auto& msg : msgs) {
    if (msg.groupID != groupID) {
      filtered.push_back(msg);
    }
  }

  msgs = move(filtered);  // 필터링된 메시지만 유지
}

int sendMessage(int uID, int groupID, char mText[]) {
  int count = 0;

  for (int user : groupMembers[groupID]) {
    if (user == uID) continue;  // 보낸 사람 제외
    if (userGroupSetting[user][groupID]) {
      Message msg;
      msg.groupID = groupID;
      strncpy(msg.text, mText, 10);  // 안전하게 복사
      msg.text[9] = '\0';            // 혹시 모를 길이 초과 방지

      inbox[user].push_back(msg);
      ++count;
    }
  }

  return count;
}

int checkMsg(int uID, char mMsg[]) {
  vector<Message>& msgs = inbox[uID];
  int msgCount = msgs.size();

  if (msgCount == 0) {
    return 0;
  }

  // 가장 최신 메시지는 벡터의 마지막
  strncpy(mMsg, msgs.back().text, 10);
  mMsg[9] = '\0';  // 혹시 모를 overflow 방지

  // 메시지 모두 삭제
  msgs.clear();

  return msgCount;
}

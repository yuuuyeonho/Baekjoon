#include <vector>
using namespace std;

struct Group {
  int groupID;
  int mNum;
  vector<pair<int, bool> > uIDs;
};

struct Message {
  char content[10];
  int groupID;
};

vector<Group> groupList;
vector<Message> userMessageBox[5001];

void init(int N) {
  userMessageBox->clear();
  Group group;
  groupList.push_back(group);
}

void createGroup(int groupID, int mNum, int uIDs[]) {
  Group group;
  group.groupID = groupID;
  group.mNum = mNum;
  for (int i = 0; i < mNum; ++i) {
    group.uIDs.push_back(make_pair(uIDs[i], true));
  }
  groupList.push_back(group);
}

int sendMessage(int uID, int groupID, char mText[]) {
  Group cur = groupList[groupID];
  int mNum = cur.mNum;
  int cnt = 0;

  Message message;
  strcpy(message.content, mText);
  message.groupID = groupID;
  for (int i = 0; i < mNum; ++i) {
    if (cur.uIDs[i].first == uID) continue;
    if (cur.uIDs[i].second == true) {
      int curUser = cur.uIDs[i].first;
      userMessageBox[curUser].push_back(message);
      cnt++;
    }
  }
  return cnt;
}

void setOnOff(int uID, int groupID) {
  Group g = groupList[groupID];
  for (int i = 0; i < g.uIDs.size(); ++i) {
    if (g.uIDs[i].first == uID) {
      if (g.uIDs[i].second == true) {
        for (auto it = userMessageBox[uID].begin();
             it != userMessageBox[uID].end();) {
          if (it->groupID == groupID) {
            it = userMessageBox[uID].erase(it);
          } else {
            ++it;
          }
        }
        g.uIDs[i].second = false;
      } else {
        g.uIDs[i].second = true;
      }
      break;
    }
  }
}

int checkMsg(int uID, char mMsg[]) {
  int ret = userMessageBox[uID].size();

  if (ret != 0) {
    mMsg = userMessageBox[uID].back().content;
  }

  userMessageBox[uID].clear();

  return ret;
}
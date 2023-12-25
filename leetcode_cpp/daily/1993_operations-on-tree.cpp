//
// Created by Anti on 2023/9/23.
//
#include <vector>

using namespace std;
class LockingTree {
 public:
  vector<pair<bool, int>> locked;
  vector<int> father;
  vector<vector<int>> children;

  LockingTree(vector<int>& parent) {
    int len = parent.size();
    father = parent;
    vector<pair<bool, int>> locked_(len, pair<bool, int>(false, -2));
    locked = locked_;
    children.resize(len);
    for (int i = 1; i < len; i++) {
      children[parent[i]].push_back(i);
    }
  }

  bool sonIsLocked(int num) {
    if (locked[num].first)
      return true;
    if (children[num].empty())
      return false;

    bool flag = false;
    for (int sons : children[num]) {
      flag = flag || sonIsLocked(sons);
    }

    return flag;
  }

  bool faIsUnlocked(int num) {
    if (num == 0)
      return !locked[0].first;
    if (locked[father[num]].first)
      return false;

    return faIsUnlocked(father[num]);
  }

  bool lock(int num, int user) {
    if (!locked[num].first) {
      locked[num] = pair<bool, int>(true, user);
      return true;
    }

    return false;
  }

  bool unlock(int num, int user) {
    bool flag = (locked[num].first && (locked[num].second == user));
    if (flag) {
      locked[num] = pair<bool, int>(false, -2);
    }

    return flag;
  }

  void upgrading(int num) {
    locked[num] = pair<bool, int>(false, -2);
    if (children[num].empty())
      return;
    for (int i : children[num]) {
      upgrading(i);
    }
  }

  bool upgrade(int num, int user) {
    if (!locked[num].first && sonIsLocked(num) && faIsUnlocked(num)) {
      upgrading(num);
      locked[num] = pair<bool, int>(true, user);
      return true;
    }

    return false;
  }
};
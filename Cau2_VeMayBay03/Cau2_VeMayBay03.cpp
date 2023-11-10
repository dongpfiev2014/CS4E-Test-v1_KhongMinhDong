#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class VeMayBay {
private:
    string tenchuyen;
    int ngaybay;
    double giave;
public:
    VeMayBay(const string& tc = "VN7159", int nb = 15, double gv = 150000)
        : tenchuyen(tc), ngaybay(nb), giave(gv) {
    }
    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin >> tenchuyen;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }
    void Xuat() const {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }
    double getgiave() const {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;
public:
    Nguoi(const string& ht = "Nguyen Van A", const string& gt = "Nam", int t = 27)
        : hoten(ht), gioitinh(gt), tuoi(t) {}
    virtual void Nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
    }
    virtual void Xuat() const {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi {
private:
    vector<VeMayBay> ve;
public:
    HanhKhach() : Nguoi() {}
    void Nhap() override {
        Nguoi::Nhap();
        int soluong;
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        cin.ignore();
        ve.clear();
        VeMayBay tempVe;
        for (int i = 0; i < soluong; i++) {
            cout << "Nhap thong tin ve may bay thu " << i + 1 << ":\n";
            tempVe.Nhap();
            ve.push_back(tempVe);
        }
    }
    void Xuat() const override {
        Nguoi::Xuat();
        cout << "So luong ve: " << ve.size() << endl;
        for (size_t i = 0; i < ve.size(); ++i) {
            cout << "Thong tin ve may bay thu " << i + 1 << ":\n";
            ve[i].Xuat();
        }
    }
    double tongtien() const {
        double tong = 0.0;
        for (const auto& v : ve) {
            tong += v.getgiave();
        }
        return tong;
    }
};
bool SoSanh(const HanhKhach& a, const HanhKhach& b) {
    return a.tongtien() > b.tongtien();
}
int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();
    vector<HanhKhach> GuestList(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho hanh khach thu " << i + 1 << endl;
        GuestList[i].Nhap();
    }
    cout << "Danh sach hanh khach va so tien phai tra:" << endl;
    for (const auto& hanhKhach : GuestList) {
        hanhKhach.Xuat();
        cout << "Tong tien phai tra: " << hanhKhach.tongtien() << endl;
    }
    sort(GuestList.begin(), GuestList.end(), SoSanh);
    cout << "Danh sach hanh khach sau khi sap xep theo chieu giam dan cua tong tien: ";
    for (const auto& hanhKhach : GuestList) {
        hanhKhach.Xuat();
        cout << "Tong tien phai tra: " << hanhKhach.tongtien() << endl;
    }
    return 0;
}

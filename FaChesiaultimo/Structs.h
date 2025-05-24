#ifndef STRUCTS_H
#define STRUCTS_H
#include <QMainWindow>
struct materia{
    QString Cod,Desc;

    bool operator==(const materia &other) const {
        return Cod == other.Cod && Desc == other.Desc;
    }
};

inline uint qHash(const materia &p, uint seed = 0) {
    return qHash(p.Cod, seed) ^ qHash(p.Desc, seed);
}

struct rigav{
    QString CodCorso,DesCorso,CodMat,DescMat,MatStu,CogStu,NomStu;
    QString strun() const{
        return CodCorso+","+DesCorso+","+CodMat+","+DescMat+","+MatStu+","+CogStu+","+NomStu;
    }
};
#endif // STRUCTS_H

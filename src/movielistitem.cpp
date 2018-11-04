#include "movielistitem.h"

#include <QMetaEnum>

MovieListItem::MovieListItem(QObject *parent)
    : ListItem(parent)
{
    initRoles();
}

MovieListItem::MovieListItem(const QVariantMap &data, QObject *parent)
{
    initRoles();

    QMapIterator<QString, QVariant> it(data);
    while (it.hasNext())
    {
        it.next();
        setData(role(it.key()), it.value());
    }
}

QString MovieListItem::id() const
{
    return data(IdRole).toString();
}

void MovieListItem::initRoles()
{
    m_roleNames.insert(IdRole,              "id"          );
    m_roleNames.insert(NameRole,            "cnname"      );
    m_roleNames.insert(ChannelRole,         "channel"     );
    m_roleNames.insert(AreaRole,            "area"        );
    m_roleNames.insert(CategoryRole,        "category"    );
    m_roleNames.insert(PublishYearRole,     "publish_year");
    m_roleNames.insert(PlayStatusRole,      "play_status" );
    m_roleNames.insert(PosterRole,          "poster"      );
    m_roleNames.insert(PosterBigRole,       "poster_b"    );
    m_roleNames.insert(PosterMiddleRole,    "poster_m"    );
    m_roleNames.insert(PosterSmallRole,     "poster_s"    );
}

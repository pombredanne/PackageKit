#ifndef __SLACK_PKGTOOLS_H
#define __SLACK_PKGTOOLS_H

#include <glib-object.h>
#include <pk-backend.h>

G_BEGIN_DECLS

#define SLACK_TYPE_PKGTOOLS slack_pkgtools_get_type()
G_DECLARE_INTERFACE(SlackPkgtools, slack_pkgtools, SLACK, PKGTOOLS, GObject)

struct _SlackPkgtoolsInterface
{
	GTypeInterface parent;

	GSList *(*collect_cache_info) (SlackPkgtools *pkgtools, const gchar *tmpl);
	void (*generate_cache) (SlackPkgtools *pkgtools,
	                        PkBackendJob *job,
	                        const gchar *tmpl);
};

GSList *slack_pkgtools_collect_cache_info(SlackPkgtools *pkgtools,
                                          const gchar *tmpl);
void slack_pkgtools_generate_cache(SlackPkgtools *pkgtools,
                                   PkBackendJob *job,
                                   const gchar *tmpl);
gboolean slack_pkgtools_download(SlackPkgtools *pkgtools,
                                 PkBackendJob *job,
                                 gchar *dest_dir_name,
                                 gchar *pkg_name);
void slack_pkgtools_install(SlackPkgtools *pkgtools,
                            PkBackendJob *job,
                            gchar *pkg_name);

class _SlackPkgtools
{
public:
	const gchar *get_name () noexcept;
	const gchar *get_mirror () noexcept;
};

G_END_DECLS

#endif /* __SLACK_PKGTOOLS_H */

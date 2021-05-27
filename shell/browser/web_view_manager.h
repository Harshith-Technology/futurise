// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_WEB_VIEW_MANAGER_H_
#define SHELL_BROWSER_WEB_VIEW_MANAGER_H_

#include <map>

#include "content/public/browser/browser_plugin_guest_manager.h"

namespace electron {

class WebViewManager : public content::BrowserPluginGuestManager {
 public:
  WebViewManager();
  ~WebViewManager() override;

  void AddGuest(int guest_instance_id,
                content::WebContents* embedder,
                content::WebContents* web_contents);
  void RemoveGuest(int guest_instance_id);
  content::WebContents* GetEmbedder(int guest_instance_id);

  static WebViewManager* GetWebViewManager(content::WebContents* web_contents);

 protected:
  // content::BrowserPluginGuestManager:
  bool ForEachGuest(content::WebContents* embedder,
                    const GuestCallback& callback) override;

 private:
  struct WebContentsWithEmbedder {
    content::WebContents* web_contents;
    content::WebContents* embedder;
  };
  // guest_instance_id => (web_contents, embedder)
  std::map<int, WebContentsWithEmbedder> web_contents_embedder_map_;

  DISALLOW_COPY_AND_ASSIGN(WebViewManager);
};

}  // namespace electron

#endif  // SHELL_BROWSER_WEB_VIEW_MANAGER_H_

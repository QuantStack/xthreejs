#ifndef XTHREE_SCENE_UTILS_HPP
#define XTHREE_SCENE_UTILS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // scene_utils declaration
    //

    template<class D>
    class xscene_utils : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xscene_utils();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using scene_utils = xw::xmaterialize<xscene_utils>;

    using scene_utils_generator = xw::xgenerator<xscene_utils>;

    //
    // scene_utils implementation
    //


    template <class D>
    inline void xscene_utils<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xscene_utils<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xscene_utils<D>::xscene_utils()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xscene_utils<D>::set_defaults()
    {
        this->_model_name() = "SceneUtilsModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xscene_utils>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xscene_utils>;
        extern template xw::xmaterialize<xthree::xscene_utils>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xscene_utils>>;
        extern template class xw::xgenerator<xthree::xscene_utils>;
        extern template xw::xgenerator<xthree::xscene_utils>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xscene_utils>>;
    #endif
#endif

#endif
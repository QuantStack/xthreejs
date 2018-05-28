#ifndef XTHREE_SCENE_HPP
#define XTHREE_SCENE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // scene declaration
    //

    template<class D>
    class xscene : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, fog);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, overrideMaterial);
        XPROPERTY(bool, derived_type, autoUpdate, true);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, background, "#ffffff");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xscene();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using scene = xw::xmaterialize<xscene>;

    using scene_generator = xw::xgenerator<xscene>;

    //
    // scene implementation
    //


    template <class D>
    inline void xscene<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(overrideMaterial, state, buffers);
        xw::set_patch_from_property(autoUpdate, state, buffers);
        xw::set_patch_from_property(background, state, buffers);
    }

    template <class D>
    inline void xscene<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(overrideMaterial, patch, buffers);
        xw::set_property_from_patch(autoUpdate, patch, buffers);
        xw::set_property_from_patch(background, patch, buffers);
    }

    template <class D>
    inline xscene<D>::xscene()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xscene<D>::set_defaults()
    {
        this->_model_name() = "SceneModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xscene>& widget)
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
        extern template class xw::xmaterialize<xthree::xscene>;
        extern template xw::xmaterialize<xthree::xscene>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xscene>>;
        extern template class xw::xgenerator<xthree::xscene>;
        extern template xw::xgenerator<xthree::xscene>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xscene>>;
    #endif
#endif

#endif
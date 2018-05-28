#ifndef XTHREE_SKELETON_HELPER_HPP
#define XTHREE_SKELETON_HELPER_HPP

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
    // skeleton_helper declaration
    //

    template<class D>
    class xskeleton_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, root);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xskeleton_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using skeleton_helper = xw::xmaterialize<xskeleton_helper>;

    using skeleton_helper_generator = xw::xgenerator<xskeleton_helper>;

    //
    // skeleton_helper implementation
    //


    template <class D>
    inline void xskeleton_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(root, state, buffers);
    }

    template <class D>
    inline void xskeleton_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(root, patch, buffers);
    }

    template <class D>
    inline xskeleton_helper<D>::xskeleton_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xskeleton_helper<D>::set_defaults()
    {
        this->_model_name() = "SkeletonHelperModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xskeleton_helper>& widget)
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
        extern template class xw::xmaterialize<xthree::xskeleton_helper>;
        extern template xw::xmaterialize<xthree::xskeleton_helper>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xskeleton_helper>>;
        extern template class xw::xgenerator<xthree::xskeleton_helper>;
        extern template xw::xgenerator<xthree::xskeleton_helper>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xskeleton_helper>>;
    #endif
#endif

#endif
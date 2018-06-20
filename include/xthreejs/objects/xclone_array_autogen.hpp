#ifndef XTHREE_CLONE_ARRAY_HPP
#define XTHREE_CLONE_ARRAY_HPP

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
    // clone_array declaration
    //

    template<class D>
    class xclone_array : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, original);
        XPROPERTY(std::vector<std::vector<double>>, derived_type, positions, std::vector<std::vector<double>>({}));
        XPROPERTY(bool, derived_type, merge, false);
        XPROPERTY(std::string, derived_type, type, "CloneArray");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xclone_array();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using clone_array = xw::xmaterialize<xclone_array>;

    using clone_array_generator = xw::xgenerator<xclone_array>;

    //
    // clone_array implementation
    //


    template <class D>
    inline void xclone_array<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(original, state, buffers);
        xw::set_patch_from_property(positions, state, buffers);
        xw::set_patch_from_property(merge, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xclone_array<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(original, patch, buffers);
        xw::set_property_from_patch(positions, patch, buffers);
        xw::set_property_from_patch(merge, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xclone_array<D>::xclone_array()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xclone_array<D>::set_defaults()
    {
        this->_model_name() = "CloneArrayModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xclone_array>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xclone_array>;
        extern template xw::xmaterialize<xthree::xclone_array>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xclone_array>>;
        extern template class xw::xgenerator<xthree::xclone_array>;
        extern template xw::xgenerator<xthree::xclone_array>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xclone_array>>;
    #endif
#endif

#endif